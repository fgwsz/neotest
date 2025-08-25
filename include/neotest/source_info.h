#ifndef NEOTEST_SOURCE_INFO_H
#define NEOTEST_SOURCE_INFO_H

#include<cstddef>//std::size_t

#include<string_view>//std::string_view

#include"macro.h"

namespace neotest{

struct SourceInfo{
    std::string_view file;
    std::size_t line;
    std::string_view line_sv;
    std::string_view info;
};
}//namespace neotest

#define NEOTEST_MAKE_SOURCE_INFO(...) \
    neotest::SourceInfo{ \
        __FILE__ \
        ,__LINE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,NEOTEST_TO_STRING(__VA_ARGS__) \
    } \
//

#endif//NEOTEST_SOURCE_INFO_H
