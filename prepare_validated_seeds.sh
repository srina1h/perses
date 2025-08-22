#!/bin/bash

# Script to clone seeds_js_fuzzing repository and copy JavaScript files from seeds folder
# to the main seeds directory

set -e  # Exit on any error

# Configuration
REPO_URL="https://github.com/srina1h/seeds_js_fuzzing"
REPO_NAME="seeds_js_fuzzing"
SEEDS_DIR="seeds"
TEMP_DIR="temp_seeds_repo"

echo "Starting seeds_js_fuzzing JavaScript file extraction..."

# Create seeds directory if it doesn't exist
if [ ! -d "$SEEDS_DIR" ]; then
    echo "Creating seeds directory..."
    mkdir -p "$SEEDS_DIR"
fi

# Remove temporary directory if it exists
if [ -d "$TEMP_DIR" ]; then
    echo "Removing existing temporary directory..."
    rm -rf "$TEMP_DIR"
fi

# Clone the repository
echo "Cloning seeds_js_fuzzing repository..."
git clone "$REPO_URL" "$TEMP_DIR"

# Check if cloning was successful
if [ ! -d "$TEMP_DIR" ]; then
    echo "Error: Failed to clone repository"
    exit 1
fi

# Check if seeds folder exists in the cloned repository
if [ ! -d "$TEMP_DIR/seeds" ]; then
    echo "Error: seeds folder not found in the repository"
    exit 1
fi

# Copy all JavaScript files from the seeds folder
echo "Copying JavaScript files from seeds folder..."
find "$TEMP_DIR/seeds" -name "*.js" -type f | while read -r js_file; do
    # Get just the filename without path
    filename=$(basename "$js_file")
    
    # Handle duplicate filenames by adding a counter
    counter=1
    final_filename="$filename"
    
    while [ -f "$SEEDS_DIR/$final_filename" ]; do
        # Remove .js extension, add counter, then add .js back
        name_without_ext="${filename%.js}"
        final_filename="${name_without_ext}_${counter}.js"
        ((counter++))
    done
    
    # Copy the file directly to seeds directory
    cp "$js_file" "$SEEDS_DIR/$final_filename"
    echo "  Copied: $filename -> $final_filename"
done

# Count the total number of JavaScript files copied
total_files=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
echo "Total JavaScript files extracted: $total_files"

# Clean up temporary directory
echo "Cleaning up temporary directory..."
rm -rf "$TEMP_DIR"

echo "seeds_js_fuzzing JavaScript file extraction completed successfully!"
echo "Files have been copied to the $SEEDS_DIR directory."
