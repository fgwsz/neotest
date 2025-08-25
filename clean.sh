#!/bin/bash
root_path=$(dirname "$(readlink -f "$0")")
build_path="$root_path/build/linux"
binary_debug_path="$root_path/binary-debug"
binary_release_path="$root_path/binary-release"
if [ -d "$build_path" ]; then
    rm -rf "$build_path"
fi
if [ -e "$binary_debug_path" ]; then
    rm -rf "$binary_debug_path"
fi
if [ -e "$binary_release_path" ]; then
    rm -rf "$binary_release_path"
fi
