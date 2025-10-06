#!/bin/bash

# Script to clone DIE-corpus repository and extract JavaScript files from v8 and jsc folders
# to the seeds directory

set -e  # Exit on any error

# Configuration
REPO_URL="https://github.com/sslab-gatech/DIE-corpus"
REPO_NAME="DIE-corpus"
SEEDS_DIR="seeds"
TEMP_DIR="temp_die_corpus"

echo "Starting DIE-corpus JavaScript file extraction..."

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
echo "Cloning DIE-corpus repository..."
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

# Process v8 folder
echo "Extracting JavaScript files from v8 folder..."
copy_js_files "$TEMP_DIR/v8" "$SEEDS_DIR"

# Process jsc folder
echo "Extracting JavaScript files from jsc folder..."
copy_js_files "$TEMP_DIR/jsc" "$SEEDS_DIR"

# Count the total number of JavaScript files copied
total_files=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
echo "Total JavaScript files extracted: $total_files"

# Optional: Trim to a random subset for testing (set SEED_LIMIT env var)
SEED_LIMIT="${SEED_LIMIT:-}"
if [ -n "$SEED_LIMIT" ] && [ "$SEED_LIMIT" -gt 0 ] && [ "$total_files" -gt "$SEED_LIMIT" ]; then
    echo "Trimming to $SEED_LIMIT random seeds for testing..."
    temp_keep_dir=$(mktemp -d)
    
    # Randomly select SEED_LIMIT files
    find "$SEEDS_DIR" -name "*.js" -type f | shuf -n "$SEED_LIMIT" | while read -r file; do
        cp "$file" "$temp_keep_dir/"
    done
    
    # Replace seeds directory with trimmed set
    rm -rf "$SEEDS_DIR"
    mv "$temp_keep_dir" "$SEEDS_DIR"
    
    trimmed_count=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
    echo "Trimmed to $trimmed_count seeds"
fi

# Clean up temporary directory
echo "Cleaning up temporary directory..."
rm -rf "$TEMP_DIR"

echo "DIE-corpus JavaScript file extraction completed successfully!"
echo "Files have been copied to the $SEEDS_DIR directory."
