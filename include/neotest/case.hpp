#ifndef NEOTEST_CASE_HPP
#define NEOTEST_CASE_HPP

#include<string_view>//::std::string_view

#include"static_string.hpp"
#include"case_dict.h"

namespace neotest::detail{

template<typename StaticString__>
struct Case;

}//namespace neotest::detail

//...: c_str_literal
#define NEOTEST_CASE(...) \
template<> \
struct neotest::detail::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)>{ \
    static void body(void); \
    inline static bool regist_flag=::neotest::CaseDict::regist( \
        ::std::string_view{__VA_ARGS__} \
        ,&::neotest::detail::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)> \
            ::body \
    ); \
}; \
void ::neotest::detail::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)> \
    ::body(void) \
//

#endif//NEOTEST_CASE_HPP
