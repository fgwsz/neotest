#!/bin/bash
root_path=$(dirname "$(readlink -f "$0")")
build_path="$root_path/build/linux/debug"
binary_debug_path="$root_path/binary-debug"

if [ -d "$build_path" ]; then
    rm -rf "$build_path"
fi

if [ -e "$binary_debug_path" ]; then
    rm -rf "$binary_debug_path"
fi
