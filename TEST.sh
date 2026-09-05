# TEST.sh

#   SPDX-License-Identifier: MIT
#   Copyright (c) 2026 Nico Erdmann
#   Compiles and executes a file and places the binary in the 'build' directory. Meant for testing.

#!/bin/bash

set -e

TEST_PATH="$1"

if [ -z "$TEST_PATH" ]; then
    echo "Error: No test path provided."
    exit 1
fi

FILENAME="${TEST_PATH##*/}"
EXECUTABLE_NAME="${FILENAME%.c}"

echo "Starting script for test: $TEST_PATH"

echo "Compiling $TEST_PATH..."
gcc -Wall -Wextra -std=c11 -Os -ffunction-sections -fdata-sections -fno-asynchronous-unwind-tables -fno-unwind-tables -Isrc "$TEST_PATH" -Wl,--gc-sections -s -o "build/$EXECUTABLE_NAME"
echo "Done!"

echo "Executing $EXECUTABLE_NAME"
./build/"$EXECUTABLE_NAME"
echo "Done!"

echo "Finished script!"
