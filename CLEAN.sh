# CLEAN.sh

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   Cleans the 'build' directory.

#!bin/bash

set -e

echo "Starting script..."

echo "Cleaning build..."
rm -rf build
mkdir build
echo "Done!"

echo "Finished Script!"