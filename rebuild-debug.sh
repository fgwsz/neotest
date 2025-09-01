#!/bin/bash
root_path=$(dirname "$(readlink -f "$0")")

cd "$root_path"

./clean-debug.sh
./build-debug.sh
