#!/usr/bin/env python3
"""
Patch V8 source files to track when allowlisted code is EXECUTED.
Uses static initialization with lazy evaluation - runs when file is first used.
"""

import sys
import os
import re
from pathlib import Path

def add_marker_to_file(filepath, v8_root):
    """Add execution marker using static variable initialization."""
    
    # Only patch .cc files
    if not str(filepath).endswith('.cc'):
        print(f"[SKIP] {filepath} (not a .cc file)", file=sys.stderr)
        return False
    
    try:
        with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
            content = f.read()
    except Exception as e:
        print(f"[SKIP] Cannot read {filepath}: {e}", file=sys.stderr)
        return False
    
    # Skip if already patched
    if 'ALLOWLIST_FILE_MARKER' in content:
        print(f"[SKIP] Already patched: {filepath}", file=sys.stderr)
        return False
    
    # Get relative path
    try:
        rel_path = filepath.relative_to(v8_root)
    except:
        rel_path = filepath.name
    
    # Create marker code that uses a static bool initialized by a lambda
    # This executes the FIRST TIME this translation unit's code runs
    marker_code = f'''
// ALLOWLIST_FILE_MARKER - Tracks when this file is executed
#include "src/init/allowlist-tracker.h"
namespace {{
  static bool __allowlist_marked__ = []() {{
    v8::internal::MarkAllowlistFile("{rel_path}");
    return true;
  }}();
}}
'''
    
    # Find a safe insertion point - after includes, before any code
    lines = content.split('\n')
    insert_idx = 0
    
    # Find the position after the last #include
    for i, line in enumerate(lines):
        if '#include' in line:
            insert_idx = i + 1
    
    # If no includes found, insert at the beginning (after comments)
    if insert_idx == 0:
        for i, line in enumerate(lines):
            stripped = line.strip()
            if stripped and not stripped.startswith('//') and not stripped.startswith('/*') and not stripped.startswith('*'):
                insert_idx = i
                break
    
    # Insert marker
    lines.insert(insert_idx, marker_code)
    new_content = '\n'.join(lines)
    
    try:
        with open(filepath, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print(f"[PATCHED] {filepath}", file=sys.stderr)
        return True
    except Exception as e:
        print(f"[ERROR] Cannot write {filepath}: {e}", file=sys.stderr)
        return False


def create_allowlist_header(v8_root):
    """Create allowlist tracker header for execution tracking."""
    
    header_path = v8_root / 'src' / 'init' / 'allowlist-tracker.h'
    header_path.parent.mkdir(parents=True, exist_ok=True)
    
    # Simple atomic flag that gets set when any allowlisted code executes
    header_content = """// Auto-generated allowlist execution tracker
#ifndef V8_INIT_ALLOWLIST_TRACKER_H_
#define V8_INIT_ALLOWLIST_TRACKER_H_

#include <atomic>
#include <cstdio>

namespace v8 {
namespace internal {

// Global flag - set to true when any allowlisted file code is EXECUTED
// Using inline to avoid multiple definition errors
inline std::atomic<bool> g_touched_allowlist{false};

// Mark that code from an allowlisted file was executed
inline void MarkAllowlistFile(const char* filename) {
  g_touched_allowlist.store(true, std::memory_order_relaxed);
}

}  // namespace internal
}  // namespace v8

#endif  // V8_INIT_ALLOWLIST_TRACKER_H_
"""
    
    with open(header_path, 'w', encoding='utf-8') as f:
        f.write(header_content)
    
    print(f"[CREATED] {header_path}", file=sys.stderr)
    return True


def patch_d8_shell(v8_root):
    """Patch d8.cc to print ALLOWLIST_HIT on exit if flag is set."""
    
    d8_cc = v8_root / 'src' / 'd8' / 'd8.cc'
    if not d8_cc.exists():
        print(f"[WARN] d8.cc not found at {d8_cc}", file=sys.stderr)
        return False
    
    try:
        with open(d8_cc, 'r', encoding='utf-8') as f:
            content = f.read()
    except:
        return False
    
    if 'ALLOWLIST_EXIT_CHECK' in content:
        print("[SKIP] d8.cc already patched", file=sys.stderr)
        return True
    
    # Add include at the top
    if 'allowlist-tracker.h' not in content:
        include_match = re.search(r'#include\s+[<"]', content)
        if include_match:
            include_pos = content.find('\n', include_match.start())
            content = (content[:include_pos+1] + 
                      '#include "src/init/allowlist-tracker.h"\n' + 
                      content[include_pos+1:])
    
    # Find main function's final return statement
    main_match = re.search(r'int\s+main\s*\([^)]*\)\s*\{', content)
    if not main_match:
        print("[WARN] Cannot find main() in d8.cc", file=sys.stderr)
        return False
    
    main_start = main_match.end()
    
    # Find the last return statement in main
    remaining = content[main_start:]
    return_matches = list(re.finditer(r'\n(\s*)return\s+', remaining))
    
    if not return_matches:
        print("[WARN] Cannot find return in main()", file=sys.stderr)
        return False
    
    # Use the last return
    last_return = return_matches[-1]
    insert_pos = main_start + last_return.start() + 1
    indent = last_return.group(1)
    
    # Insert check before return
    check_code = f'''{indent}// ALLOWLIST_EXIT_CHECK
{indent}if (v8::internal::g_touched_allowlist.load(std::memory_order_relaxed)) {{
{indent}  fprintf(stderr, "ALLOWLIST_HIT\\n");
{indent}  fflush(stderr);
{indent}}}
'''
    
    new_content = content[:insert_pos] + check_code + content[insert_pos:]
    
    try:
        with open(d8_cc, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print("[PATCHED] d8.cc", file=sys.stderr)
        return True
    except Exception as e:
        print(f"[ERROR] Cannot patch d8.cc: {e}", file=sys.stderr)
        return False


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
    
    # Create header
    create_allowlist_header(v8_root)
    
    # Read allowlist
    with open(allowlist_file, 'r') as f:
        allowlist = [line.strip() for line in f if line.strip()]
    
    print(f"[INFO] Found {len(allowlist)} files in allowlist", file=sys.stderr)
    
    # Patch each .cc file
    patched_count = 0
    for rel_path in allowlist:
        file_path = v8_root / rel_path
        
        if file_path.exists() and file_path.suffix in ['.cc', '.cpp']:
            if add_marker_to_file(file_path, v8_root):
                patched_count += 1
    
    # Patch d8
    patch_d8_shell(v8_root)
    
    print(f"\n[SUCCESS] Patched {patched_count} files", file=sys.stderr)
    print(f"[INFO] V8 instrumented to track allowlist execution (lazy static init)", file=sys.stderr)


if __name__ == '__main__':
    main()
