#!/bin/bash
# Copyright lowRISC contributors.
# Licensed under the Apache License, Version 2.0, see LICENSE for details.
# SPDX-License-Identifier: Apache-2.0
#
# Install development build dependencies for different Linux distributions
#

set -e

[ -f /etc/os-release ] || (
  echo "/etc/os-release doesn't exist."
  exit 1
)
. /etc/os-release

[ ! -z "$VERILATOR_VERSION" ] || (
  echo "VERILATOR_VERSION must be set."
  exit 1
)
[ ! -z "$VERIBLE_VERSION" ] || (
  echo "VERIBLE_VERSION must be set."
  exit 1
)
[ ! -z "$RISCV_TOOLCHAIN_TAR_VERSION" ] || (
  echo "RISCV_TOOLCHAIN_TAR_VERSION must be set."
  exit 1
)
[ ! -z "$RISCV_TOOLCHAIN_TAR_VARIANT" ] || (
  echo "RISCV_TOOLCHAIN_TAR_VARIANT must be set."
  exit 1
)

SUDO_CMD=""
if [ $(id -u) -ne 0 ]; then
  SUDO_CMD="sudo "
fi

case "$ID-$VERSION_ID" in
  ubuntu-16.04)
    # Curl must be available to get the repo key below.
    $SUDO_CMD apt-get update
    $SUDO_CMD apt-get install -y curl

    # Make Verilator repository available
    curl -Ls https://download.opensuse.org/repositories/home:phiwag:edatools/xUbuntu_16.04/Release.key | $SUDO_CMD apt-key add -
    $SUDO_CMD sh -c "echo 'deb http://download.opensuse.org/repositories/home:/phiwag:/edatools/xUbuntu_16.04/ /' > /etc/apt/sources.list.d/edatools.list"
    $SUDO_CMD apt-get update

    # Uninstall distribution-provided version to get a newer version through pip
    $SUDO_CMD apt-get remove -y python3-yaml

    # Packaged dependencies
    $SUDO_CMD apt-get install -y \
      device-tree-compiler \
      python3 \
      python3-pip \
      python3-setuptools \
      python3-wheel \
      srecord \
      zlib1g-dev \
      git \
      make \
      autoconf \
      g++ \
      flex \
      bison \
      libelf-dev \
      clang-format \
      "verilator-$VERILATOR_VERSION" \
      xz-utils

    # Python dependencies
    #
    # Installing six is a workaround for pip dependency resolution: six is
    # already installed as system package with a version below the required
    # one. Explicitly installing six through pip gets us a supported version.
    #
    # Updating pip and setuptools is required to have these tools properly
    # parse Python-version metadata, which some packages uses to specify that
    # an older version of a package must be used for a certain Python version.
    # If that information is not read, pip installs the latest version, which
    # then fails to run.
    $SUDO_CMD pip3 install -U pip six

    # There's been a bit of a kerfuffle about setuptools version 50, which
    # breaks importing distutils on Debian/Ubuntu systems. Make sure we don't
    # pick it up until the dust has settled and things work again.
    $SUDO_CMD pip3 install -U 'setuptools < 50.0.0'

    $SUDO_CMD pip3 install -U -r python-requirements.txt

    # Install Verible
    mkdir -p build/verible
    cd build/verible
    curl -Ls -o verible.tar.gz "https://github.com/google/verible/releases/download/$VERIBLE_VERSION/verible-$VERIBLE_VERSION-Ubuntu-16.04-xenial-x86_64.tar.gz"
    $SUDO_CMD mkdir -p /tools/verible && $SUDO_CMD chmod 777 /tools/verible
    tar -C /tools/verible -xf verible.tar.gz --strip-components=1
    echo "##vso[task.prependpath]/tools/verible/bin"
    ;;

  *)
    echo Unknown distribution. Please extend this script!
    exit 1
    ;;
esac

# Install pre-compiled toolchain (for all distributions)
TOOLCHAIN_URL="https://github.com/lowRISC/lowrisc-toolchains/releases/download/$RISCV_TOOLCHAIN_TAR_VERSION/$RISCV_TOOLCHAIN_TAR_VARIANT-$RISCV_TOOLCHAIN_TAR_VERSION.tar.xz"
mkdir -p build/toolchain
curl -Ls -o build/toolchain/rv32-toolchain.tar.xz "$TOOLCHAIN_URL"
$SUDO_CMD mkdir -p /tools/riscv && $SUDO_CMD chmod 777 /tools/riscv
tar -C /tools/riscv -xf build/toolchain/rv32-toolchain.tar.xz --strip-components=1
echo "##vso[task.prependpath]/tools/riscv/bin"
