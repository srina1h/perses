#!/usr/bin/env bash
set -euo pipefail

# Generate an AFL++ allowlist from recently modified files in a git repo.
# Default behavior: last 6 months, commit messages containing fix AND bug (case-insensitive), only under src/.
# Usage:
#   GEN_REPO=/path/to/v8 GEN_SINCE_MONTHS=6 ./gen_allowlist_from_git.sh > allowlist.txt
# Optional env:
#   GREP1, GREP2 ... (commit message filters; all must match). Default: fix, bug
#   SRC_PREFIX (default: src/)

: "${GEN_REPO:?Set GEN_REPO to the git repository root (e.g., /workspace/v8)}"
: "${GEN_SINCE_MONTHS:=6}"
: "${SRC_PREFIX:=src/}"

cd "${GEN_REPO}"

since_date=$(date -u -d "${GEN_SINCE_MONTHS} months ago" +%Y-%m-%d 2>/dev/null || true)
if [ -z "${since_date}" ]; then
  # macOS BSD date fallback
  since_date=$(date -u -v -"${GEN_SINCE_MONTHS}"m +%Y-%m-%d)
fi

# Build grep args: default to fix & bug
GREP_ARGS=("--regexp-ignore-case")
if [ -z "${GREP1:-}" ] && [ -z "${GREP2:-}" ]; then
  GREP_ARGS+=("--grep=fix" "--grep=bug" "--all-match")
else
  i=1
  while true; do
    key="GREP${i}"
    val="${!key:-}"
    if [ -z "${val}" ]; then break; fi
    GREP_ARGS+=("--grep=${val}")
    i=$((i+1))
  done
  GREP_ARGS+=("--all-match")
fi

# Gather changed files and restrict to src/
changed=$(git log --since="${since_date}" "${GREP_ARGS[@]}" --name-only --pretty=format: | awk 'NF' | sort -u)
changed_src=$(printf '%s\n' "$changed" | grep -E "^${SRC_PREFIX}" || true)

# Stats to stderr for visibility
echo "number of files changed in the last ${GEN_SINCE_MONTHS} months (matching filters)" 1>&2
printf '%s\n' "$changed_src" | wc -l 1>&2
echo "total number of files under ${SRC_PREFIX}" 1>&2
git ls-files "${SRC_PREFIX}*" | wc -l 1>&2

# Output allowlist: one path per line
printf '%s\n' "$changed_src"


