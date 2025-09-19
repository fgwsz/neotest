#ifndef VNITEST_SOURCE_INFO_H
#define VNITEST_SOURCE_INFO_H

#include<string_view>//::std::string_view
#include<string>//::std::string

#include<vnitest/macro.h>

namespace vnitest{

struct SourceInfo{
    ::std::string_view file,line;
    ::std::string info;
};
}//namespace vnitest

#define VNITEST_MAKE_SOURCE_INFO(...) \
    ::vnitest::SourceInfo{ \
        __FILE__ \
        ,VNITEST_TO_STRING(__LINE__) \
        ,::std::string{__VA_ARGS__} \
    } \
//

#endif//VNITEST_SOURCE_INFO_H
