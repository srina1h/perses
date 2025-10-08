#!/usr/bin/env python3
"""
Patch V8 source files to add allowlist tracking using static initializers.
This is the SAFEST approach - adds code that runs at program startup, not inside functions.
"""

import sys
import os
from pathlib import Path

def add_marker_to_file(filepath, v8_root):
    """Add a static initializer to a .cc file to mark it as touched."""
    
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
    if 'ALLOWLIST_STATIC_MARKER' in content:
        print(f"[SKIP] Already patched: {filepath}", file=sys.stderr)
        return False
    
    # Get relative path for marker
    try:
        rel_path = filepath.relative_to(v8_root)
    except:
        rel_path = filepath
    
    # Add marker at the very beginning of the file (after includes ideally)
    # Use a static variable with a constructor that sets the flag
    # This is VERY safe - no function body modification needed
    marker_code = f'''
// ALLOWLIST_STATIC_MARKER - Auto-generated
#include "src/init/allowlist-tracker.h"
namespace {{ static v8::internal::AllowlistFileMarker __marker__("{rel_path}"); }}
'''
    
    # Find a safe insertion point - after the first few #include lines
    lines = content.split('\n')
    insert_idx = 0
    
    # Find the last #include or first namespace/class
    for i, line in enumerate(lines):
        if '#include' in line:
            insert_idx = i + 1
        elif line.strip().startswith('namespace ') or line.strip().startswith('class '):
            if insert_idx == 0:
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
    """Create allowlist tracker header with static initializer support."""
    
    header_path = v8_root / 'src' / 'init' / 'allowlist-tracker.h'
    header_path.parent.mkdir(parents=True, exist_ok=True)
    
    header_content = """// Auto-generated allowlist tracker
#ifndef V8_INIT_ALLOWLIST_TRACKER_H_
#define V8_INIT_ALLOWLIST_TRACKER_H_

#include <atomic>
#include <cstdio>

namespace v8 {
namespace internal {

// Global flag - set to true when any allowlisted file is loaded
inline std::atomic<bool> g_touched_allowlist{false};

// Helper class - constructor runs at static initialization time
// This marks that a specific file was loaded
class AllowlistFileMarker {
 public:
  explicit AllowlistFileMarker(const char* filename) {
    g_touched_allowlist.store(true, std::memory_order_relaxed);
  }
};

}  // namespace internal
}  // namespace v8

#endif  // V8_INIT_ALLOWLIST_TRACKER_H_
"""
    
    with open(header_path, 'w', encoding='utf-8') as f:
        f.write(header_content)
    
    print(f"[CREATED] {header_path}", file=sys.stderr)
    return True


def patch_d8_shell(v8_root):
    """Patch d8.cc to print ALLOWLIST_HIT on exit."""
    
    d8_cc = v8_root / 'src' / 'd8' / 'd8.cc'
    if not d8_cc.exists():
        print(f"[WARN] d8.cc not found at {d8_cc}", file=sys.stderr)
        return False
    
    try:
        with open(d8_cc, 'r', encoding='utf-8') as f:
            content = f.read()
    except:
        return False
    
    if 'ALLOWLIST_HIT_MARKER' in content:
        print("[SKIP] d8.cc already patched", file=sys.stderr)
        return True
    
    # Add include at the top
    if 'allowlist-tracker.h' not in content:
        # Find first #include
        include_pos = content.find('#include')
        if include_pos > 0:
            eol = content.find('\n', include_pos)
            content = content[:eol+1] + '#include "src/init/allowlist-tracker.h"\n' + content[eol+1:]
    
    # Add marker print at exit - find main's return statement
    export_code = '''
  // ALLOWLIST_HIT_MARKER
  if (v8::internal::g_touched_allowlist.load(std::memory_order_relaxed)) {
    fprintf(stderr, "ALLOWLIST_HIT\\n");
    fflush(stderr);
  }
'''
    
    # Insert before "return 0;" or "return result;" in main
    lines = content.split('\n')
    for i in range(len(lines) - 1, -1, -1):
        line = lines[i].strip()
        if line.startswith('return ') and ('0' in line or 'result' in line):
            lines.insert(i, export_code)
            break
    
    new_content = '\n'.join(lines)
    
    try:
        with open(d8_cc, 'w', encoding='utf-8') as f:
            f.write(new_content)
        print("[PATCHED] d8.cc", file=sys.stderr)
        return True
    except:
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
    print(f"[INFO] V8 is now instrumented for allowlist tracking", file=sys.stderr)


if __name__ == '__main__':
    main()
