#!/usr/bin/env python3
"""
Auto-patcher for V8 source files to add allowlist tracking.
Adds a single function call to mark when allowlisted files are executed.
"""

import sys
import os
import re
from pathlib import Path

def add_marker_to_file(filepath, v8_root):
    """Add MarkAllowlistTouched() call to the first function in a C++ file."""
    
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
    except Exception as e:
        print(f"[SKIP] Cannot read {filepath}: {e}", file=sys.stderr)
        return False
    
    # Skip if already patched
    if 'MarkAllowlistTouched' in content or 'ALLOWLIST_INSTRUMENTED' in content:
        print(f"[SKIP] Already patched: {filepath}", file=sys.stderr)
        return False
    
    # Find first function body (after opening brace of function)
    # Look for pattern: function_name(...) { or function_name(...)\n{
    pattern = r'(\n[^\n]*\([^)]*\)\s*(?:const|override|final|noexcept)*\s*\{)'
    match = re.search(pattern, content)
    
    if not match:
        print(f"[SKIP] No function found: {filepath}", file=sys.stderr)
        return False
    
    # Insert marker after the opening brace
    insert_pos = match.end()
    
    marker_code = "\n  v8::internal::MarkAllowlistTouched(); // ALLOWLIST_INSTRUMENTED\n"
    
    new_content = content[:insert_pos] + marker_code + content[insert_pos:]
    
    # Write back
    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print(f"[PATCHED] {filepath}", file=sys.stderr)
        return True
    except Exception as e:
        print(f"[ERROR] Cannot write {filepath}: {e}", file=sys.stderr)
        return False


def patch_d8_shell(v8_root):
    """Patch d8.cc to export the allowlist flag on exit."""
    
    d8_cc = v8_root / 'src' / 'd8' / 'd8.cc'
    if not d8_cc.exists():
        print(f"[ERROR] d8.cc not found at {d8_cc}", file=sys.stderr)
        return False
    
    with open(d8_cc, 'r', encoding='utf-8') as f:
        content = f.read()
    
    if 'ALLOWLIST_HIT_EXPORT' in content:
        print("[SKIP] d8.cc already patched", file=sys.stderr)
        return True
    
    # Find main() function's return statement
    # Add export just before the final return
    export_code = """
  // ALLOWLIST_HIT_EXPORT - report if allowlist was touched
  if (v8::internal::g_touched_allowlist) {
    fprintf(stderr, "ALLOWLIST_HIT\\n");
    fflush(stderr);
  }
"""
    
    # Insert before the last "return" in main
    lines = content.split('\n')
    for i in range(len(lines) - 1, -1, -1):
        if 'return' in lines[i] and 'main' in content[:content.find('\n'.join(lines[:i]))]:
            lines.insert(i, export_code)
            break
    
    new_content = '\n'.join(lines)
    
    with open(d8_cc, 'w', encoding='utf-8') as f:
        f.write(new_content)
    
    print("[PATCHED] d8.cc - added allowlist export", file=sys.stderr)
    return True


def create_allowlist_header(v8_root):
    """Create the allowlist tracking header file."""
    
    header_path = v8_root / 'src' / 'init' / 'allowlist-tracker.h'
    
    header_content = """// Auto-generated allowlist tracker
#ifndef V8_INIT_ALLOWLIST_TRACKER_H_
#define V8_INIT_ALLOWLIST_TRACKER_H_

namespace v8 {
namespace internal {

// Thread-local flag to track if any allowlisted code was executed
extern thread_local bool g_touched_allowlist;

// Mark that allowlisted code has been touched
inline void MarkAllowlistTouched() {
  g_touched_allowlist = true;
}

}  // namespace internal
}  // namespace v8

#endif  // V8_INIT_ALLOWLIST_TRACKER_H_
"""
    
    with open(header_path, 'w', encoding='utf-8') as f:
        f.write(header_content)
    
    print(f"[CREATED] {header_path}", file=sys.stderr)
    
    # Also create the .cc file to define the variable
    cc_path = v8_root / 'src' / 'init' / 'allowlist-tracker.cc'
    cc_content = """// Auto-generated allowlist tracker implementation
#include "src/init/allowlist-tracker.h"

namespace v8 {
namespace internal {

thread_local bool g_touched_allowlist = false;

}  // namespace internal
}  // namespace v8
"""
    
    with open(cc_path, 'w', encoding='utf-8') as f:
        f.write(cc_content)
    
    print(f"[CREATED] {cc_path}", file=sys.stderr)
    return True


def main():
    if len(sys.argv) < 3:
        print("Usage: patch_v8_allowlist.py <v8_root> <allowlist_file>", file=sys.stderr)
        sys.exit(1)
    
    v8_root = Path(sys.argv[1]).resolve()
    allowlist_file = Path(sys.argv[2]).resolve()
    
    if not v8_root.exists():
        print(f"ERROR: V8 root not found: {v8_root}", file=sys.stderr)
        sys.exit(1)
    
    if not allowlist_file.exists():
        print(f"ERROR: Allowlist file not found: {allowlist_file}", file=sys.stderr)
        sys.exit(1)
    
    print(f"[INFO] Patching V8 at: {v8_root}", file=sys.stderr)
    print(f"[INFO] Using allowlist: {allowlist_file}", file=sys.stderr)
    
    # Create allowlist tracker header
    create_allowlist_header(v8_root)
    
    # Read allowlist
    with open(allowlist_file, 'r') as f:
        allowlist = [line.strip() for line in f if line.strip()]
    
    print(f"[INFO] Found {len(allowlist)} files in allowlist", file=sys.stderr)
    
    # Patch each file in allowlist
    patched_count = 0
    for rel_path in allowlist:
        # Remove leading src/ if present
        if rel_path.startswith('src/'):
            file_path = v8_root / rel_path
        else:
            file_path = v8_root / 'src' / rel_path
        
        if file_path.exists() and (file_path.suffix == '.cc' or file_path.suffix == '.cpp'):
            # Add include at top of file
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                
                if 'allowlist-tracker.h' not in content:
                    # Add include after first #include or at top
                    include_line = '#include "src/init/allowlist-tracker.h"\n'
                    if '#include' in content:
                        first_include = content.find('#include')
                        eol = content.find('\n', first_include)
                        content = content[:eol+1] + include_line + content[eol+1:]
                    else:
                        content = include_line + content
                    
                    with open(file_path, 'w', encoding='utf-8') as f:
                        f.write(content)
                
                if add_marker_to_file(file_path, v8_root):
                    patched_count += 1
            except Exception as e:
                print(f"[ERROR] Failed to patch {file_path}: {e}", file=sys.stderr)
    
    # Patch d8.cc
    patch_d8_shell(v8_root)
    
    print(f"\n[SUCCESS] Patched {patched_count} files", file=sys.stderr)
    print(f"[INFO] V8 is now instrumented for allowlist tracking", file=sys.stderr)


if __name__ == '__main__':
    main()

