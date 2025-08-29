#ifndef NEOTEST_REGEX_H
#define NEOTEST_REGEX_H

#include<string_view>//::std::string_view
#include<regex>//::std::regex

namespace neotest{

struct RegEx{
    ::std::string_view pattern;
    ::std::regex object;
};

}//namespace neotest

//...: c_str_literal
#define NEOTEST_MAKE_REGEX(...) \
    ::neotest::RegEx{ \
        ::std::string_view{__VA_ARGS__} \
        ,::std::regex{__VA_ARGS__} \
    }\
//

#endif//NEOTEST_REGEX_H
