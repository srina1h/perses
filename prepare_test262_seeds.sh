#!/bin/bash

# Script to clone Test262 repository and extract JavaScript files from /test directory
# to the seeds directory

set -e  # Exit on any error

# Configuration
REPO_URL="https://github.com/tc39/test262"
REPO_NAME="test262"
SEEDS_DIR="seeds"
TEMP_DIR="temp_test262"

echo "Starting Test262 JavaScript file extraction..."

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
echo "Cloning Test262 repository..."
git clone "$REPO_URL" "$TEMP_DIR"

# Check if cloning was successful
if [ ! -d "$TEMP_DIR" ]; then
    echo "Error: Failed to clone repository"
    exit 1
fi

# Function to copy JavaScript files from a directory (flattened structure)
copy_js_files() {
    local source_dir="$1"
    local target_dir="$2"
    
    if [ -d "$source_dir" ]; then
        echo "Processing $source_dir..."
        
        # Find all .js files recursively and copy them directly to seeds directory
        find "$source_dir" -name "*.js" -type f | while read -r js_file; do
            # Get just the filename without path
            filename=$(basename "$js_file")
            
            # Handle duplicate filenames by adding a counter
            counter=1
            final_filename="$filename"
            
            while [ -f "$target_dir/$final_filename" ]; do
                # Remove .js extension, add counter, then add .js back
                name_without_ext="${filename%.js}"
                final_filename="${name_without_ext}_${counter}.js"
                ((counter++))
            done
            
            # Copy the file directly to seeds directory
            cp "$js_file" "$target_dir/$final_filename"
            echo "  Copied: $filename -> $final_filename"
        done
    else
        echo "Warning: Directory $source_dir does not exist"
    fi
}

# Process test folder
echo "Extracting JavaScript files from test folder..."
copy_js_files "$TEMP_DIR/test" "$SEEDS_DIR"

# Count the total number of JavaScript files copied
total_files=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
echo "Total JavaScript files extracted: $total_files"

# Clean up temporary directory
echo "Cleaning up temporary directory..."
rm -rf "$TEMP_DIR"

echo "Test262 JavaScript file extraction completed successfully!"
echo "Files have been copied to the $SEEDS_DIR directory."
