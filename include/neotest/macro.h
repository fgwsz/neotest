#ifndef NEOTEST_MACRO_H

// 基础字符串化宏（直接转换）
#define NEOTEST_STRINGIFY(x) #x

// 增强版宏（支持嵌套宏展开）
#define NEOTEST_TO_STRING(x) STRINGIFY(x)

#endif NEOTEST_MACRO_H
