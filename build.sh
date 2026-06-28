#!/bin/bash

# 清理旧的构建文件
rm -rf build/*

# 配置项目
cmake -B build -DCMAKE_POLICY_VERSION_MINIMUM=3.5 .

# 编译项目
cmake --build build -j$(nproc)