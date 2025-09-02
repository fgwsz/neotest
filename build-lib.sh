#!/bin/bash

# 获取脚本所在目录的绝对路径
root_path=$(dirname "$(readlink -f "$0")")
project_name=$(basename "$root_path")
build_path="$root_path/build/lib"

# 创建构建目录
mkdir -p "$build_path"

# 备份原始 CMakeLists.txt
if [ -f "$root_path/CMakeLists.txt" ]; then
    mv "$root_path/CMakeLists.txt" "$root_path/CMakeLists.txt.bak"
fi

# 复制 lib.cmake 为 CMakeLists.txt
if [ -f "$root_path/lib.cmake" ]; then
    cp "$root_path/lib.cmake" "$root_path/CMakeLists.txt"
else
    echo "错误: 找不到 lib.cmake 文件"
    exit 1
fi

# 进入构建目录并运行 CMake
cd "$build_path" || exit 1
cmake "$root_path"
make

# 返回原始目录并恢复 CMakeLists.txt
cd "$root_path" || exit 1
if [ -f "$root_path/CMakeLists.txt.bak" ]; then
    mv "$root_path/CMakeLists.txt.bak" "$root_path/CMakeLists.txt"
fi
