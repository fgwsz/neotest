#ifndef VNITEST_REGEX_H
#define VNITEST_REGEX_H

#include<string_view>//::std::string_view
#include<regex>//::std::regex

namespace vnitest{

struct RegEx{
    ::std::string_view pattern;
    ::std::regex object;
};

}//namespace vnitest

//...: c_str_literal
#define VNITEST_MAKE_REGEX(...) \
    ::vnitest::RegEx{ \
        ::std::string_view{__VA_ARGS__} \
        ,::std::regex{__VA_ARGS__} \
    }\
//

#endif//VNITEST_REGEX_H
