#!/usr/bin/env bash

set -o nounset
set -o pipefail
set -o errexit

readonly SCRIPT_DIR=$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")" &> /dev/null && pwd)

source "${SCRIPT_DIR}/constants.sh" || exit 1

shfmt_args=(
  -w   # Overwrite files in place
  -i=2 # 2-space indentation
  -ci  # Indent case branches
  -bn  # Place binary operators at line start
  -sr  # Add spaces after redirect operators
)

readonly VERSION="3.11.0"
readonly OS_NAME="$(uname -s | tr '[:upper:]' '[:lower:]')"

readonly BIN_NAME="shfmt_v${VERSION}_${OS_NAME}_amd64"
readonly SHFMT_DIR="${SCRIPT_DIR}/shfmt_binaries"
mkdir -p "${SHFMT_DIR}" || true
readonly BIN_FULL_PATH="${SHFMT_DIR}/${BIN_NAME}"
if [[ ! -f "${BIN_FULL_PATH}" ]]; then
  echo "Downloading ${BIN_NAME}"
  curl -L https://github.com/mvdan/sh/releases/download/v${VERSION}/${BIN_NAME} -o "${BIN_FULL_PATH}"
  chmod +x "${BIN_FULL_PATH}"
fi

while IFS= read -r -d '' file; do
  if ! "${BIN_FULL_PATH}" "${shfmt_args[@]}" "${file}"; then
    echo "[WARNING] Formatting skipped (invalid syntax): ${file}" >&2
  fi
done < <(find "${WORKSPACE_ROOT}" -type f -name "*.sh" -print0)

echo "Formatting completed (some files may need manual review)"
