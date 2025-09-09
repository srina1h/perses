#!/bin/bash

# Script to clone DIE-corpus repository and extract JavaScript files from specific folders
# Also clones direct engine repositories for the most up-to-date tests
# to the seeds directory

set -e  # Exit on any error

# Configuration
DIE_REPO_URL="https://github.com/sslab-gatech/DIE-corpus"
V8_REPO_URL="https://github.com/v8/v8"
FIREFOX_REPO_URL="https://github.com/mozilla-firefox/firefox"
WEBKIT_REPO_URL="https://github.com/WebKit/WebKit"
SEEDS_DIR="seeds"
TEMP_DIR="temp_repos"

echo "Starting comprehensive JavaScript test file extraction..."

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

# Create temporary directory
mkdir -p "$TEMP_DIR"

# Function to clone specific folders using sparse checkout
clone_sparse() {
    local repo_url="$1"
    local repo_name="$2"
    local target_dir="$3"
    shift 3
    local folders=("$@")
    
    echo "Cloning $repo_name repository (sparse checkout)..."
    git clone --filter=blob:none --sparse "$repo_url" "$target_dir"
    
    cd "$target_dir"
    git sparse-checkout init --cone
    git sparse-checkout set "${folders[@]}"
    cd - > /dev/null
}

# Clone DIE-corpus repository with specific folders
clone_sparse "$DIE_REPO_URL" "DIE-corpus" "$TEMP_DIR/DIE-corpus" "ChakraCore" "js-vuln-db" "jit"

# Clone v8 repository with specific folder
clone_sparse "$V8_REPO_URL" "v8" "$TEMP_DIR/v8" "test/mjsunit"

# Clone Firefox repository with specific folders
clone_sparse "$FIREFOX_REPO_URL" "Firefox" "$TEMP_DIR/firefox" "js/src/tests" "js/src/jit-test"

# Clone WebKit repository with specific folder
clone_sparse "$WEBKIT_REPO_URL" "WebKit" "$TEMP_DIR/WebKit" "JSTests"

# Check if cloning was successful
if [ ! -d "$TEMP_DIR/DIE-corpus" ] || [ ! -d "$TEMP_DIR/v8" ] || [ ! -d "$TEMP_DIR/firefox" ] || [ ! -d "$TEMP_DIR/WebKit" ]; then
    echo "Error: Failed to clone one or more repositories"
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

# Process DIE-corpus folders
echo "Extracting JavaScript files from DIE-corpus ChakraCore folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/ChakraCore" "$SEEDS_DIR"

echo "Extracting JavaScript files from DIE-corpus js-vuln-db folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/js-vuln-db" "$SEEDS_DIR"

echo "Extracting JavaScript files from DIE-corpus jit folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/jit" "$SEEDS_DIR"

# Process v8 repository - mjsunit folder
echo "Extracting JavaScript files from v8/test/mjsunit folder..."
copy_js_files "$TEMP_DIR/v8/test/mjsunit" "$SEEDS_DIR"

# Process Firefox repository - tests and jit-test folders
echo "Extracting JavaScript files from firefox/js/src/tests folder..."
copy_js_files "$TEMP_DIR/firefox/js/src/tests" "$SEEDS_DIR"

echo "Extracting JavaScript files from firefox/js/src/jit-test folder..."
copy_js_files "$TEMP_DIR/firefox/js/src/jit-test" "$SEEDS_DIR"

# Process WebKit repository - JSTests folder
echo "Extracting JavaScript files from WebKit/JSTests folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests" "$SEEDS_DIR"


# Count the total number of JavaScript files copied
total_files=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
echo "Total JavaScript files extracted: $total_files"

# Clean up temporary directory
echo "Cleaning up temporary directory..."
rm -rf "$TEMP_DIR"

echo "Comprehensive JavaScript test file extraction completed successfully!"
echo "Files have been copied to the $SEEDS_DIR directory."
echo ""
echo "Sources included:"
echo "  - DIE-corpus: ChakraCore, js-vuln-db, jit folders"
echo "  - v8: test/mjsunit folder"
echo "  - Firefox: js/src/tests and js/src/jit-test folders"
echo "  - WebKit: JSTests folder"
