#!/bin/bash
root_path=$(dirname "$(readlink -f "$0")")

cd "$root_path"

./build-debug.sh
./binary-debug
