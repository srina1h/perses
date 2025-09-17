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

# Clone Firefox repository with specific folders (restricted)
clone_sparse "$FIREFOX_REPO_URL" "Firefox" "$TEMP_DIR/firefox" "js/src/jit-test" "js/src/tests/non262"

# Clone WebKit repository with specific folders (restricted)
clone_sparse "$WEBKIT_REPO_URL" "WebKit" "$TEMP_DIR/WebKit" \
    "JSTests/es6" \
    "JSTests/exceptionFuzz" \
    "JSTests/executableAllocationFuzz" \
    "JSTests/microbenchmarks" \
    "JSTests/perf" \
    "JSTests/slowMicrobenchmarks" \
    "JSTests/stress"

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
        
        # Count and copy .js files; avoid subshell so the counter persists
        local copied_count=0
        while IFS= read -r js_file; do
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
            # echo "  Copied: $filename -> $final_filename"
            copied_count=$((copied_count + 1))
        done < <(find "$source_dir" -name "*.js" -type f)

        echo "Copied $copied_count JavaScript files from $source_dir."
        # Expose the count to callers for aggregation
        LAST_COPIED_COUNT=$copied_count
    else
        echo "Warning: Directory $source_dir does not exist"
        LAST_COPIED_COUNT=0
    fi
}

# Per-repository aggregations
die_total=0
v8_total=0
firefox_total=0
webkit_total=0

# Process DIE-corpus folders
echo "Extracting JavaScript files from DIE-corpus ChakraCore folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/ChakraCore" "$SEEDS_DIR"
die_total=$((die_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from DIE-corpus js-vuln-db folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/js-vuln-db" "$SEEDS_DIR"
die_total=$((die_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from DIE-corpus jit folder..."
copy_js_files "$TEMP_DIR/DIE-corpus/jit" "$SEEDS_DIR"
die_total=$((die_total + LAST_COPIED_COUNT))

# Process v8 repository - mjsunit folder
echo "Extracting JavaScript files from v8/test/mjsunit folder..."
copy_js_files "$TEMP_DIR/v8/test/mjsunit" "$SEEDS_DIR"
v8_total=$((v8_total + LAST_COPIED_COUNT))

# Process Firefox repository - jit-test and tests/non262 folders
echo "Extracting JavaScript files from firefox/js/src/jit-test folder..."
copy_js_files "$TEMP_DIR/firefox/js/src/jit-test" "$SEEDS_DIR"
firefox_total=$((firefox_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from firefox/js/src/tests/non262 folder..."
copy_js_files "$TEMP_DIR/firefox/js/src/tests/non262" "$SEEDS_DIR"
firefox_total=$((firefox_total + LAST_COPIED_COUNT))

# Process WebKit repository - selected JSTests subfolders
echo "Extracting JavaScript files from WebKit/JSTests/es6 folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/es6" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/exceptionFuzz folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/exceptionFuzz" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/executableAllocationFuzz folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/executableAllocationFuzz" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/microbenchmarks folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/microbenchmarks" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/perf folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/perf" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/slowMicrobenchmarks folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/slowMicrobenchmarks" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))

echo "Extracting JavaScript files from WebKit/JSTests/stress folder..."
copy_js_files "$TEMP_DIR/WebKit/JSTests/stress" "$SEEDS_DIR"
webkit_total=$((webkit_total + LAST_COPIED_COUNT))


# Per-repository breakdown
echo ""
echo "Per-repository totals:"
echo "  - DIE-corpus total: $die_total"
echo "  - v8 total: $v8_total"
echo "  - Firefox total: $firefox_total"
echo "  - WebKit total: $webkit_total"

# Count the grand total number of JavaScript files copied
total_files=$(find "$SEEDS_DIR" -name "*.js" -type f | wc -l)
echo "Grand total JavaScript files extracted: $total_files"

# Clean up temporary directory
echo "Cleaning up temporary directory..."
rm -rf "$TEMP_DIR"

echo "Comprehensive JavaScript test file extraction completed successfully!"
echo "Files have been copied to the $SEEDS_DIR directory."
echo ""
echo "Sources included:"
echo "  - DIE-corpus: ChakraCore, js-vuln-db, jit folders"
echo "  - v8: test/mjsunit folder"
echo "  - Firefox: js/src/jit-test and js/src/tests/non262 folders"
echo "  - WebKit: JSTests subfolders: es6, exceptionFuzz, executableAllocationFuzz, microbenchmarks, perf, slowMicrobenchmarks, stress"
