# CLEAN.sh

#   About: Cleans the 'build' directory.
#   Initial Commit: INIT
#   Commit Year: 2026
#   Licensed Under: MIT
#   Committer: Nico Erdmann
#   Author: Nico Erdmann

#!bin/bash

set -e

echo "Starting script..."

echo "Cleaning build..."
rm -rf build
mkdir build
echo "Done!"

echo "Finished Script!"