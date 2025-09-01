#!/bin/bash
root_path=$(dirname "$(readlink -f "$0")")

cd "$root_path"

./build-release.sh
./binary-release
