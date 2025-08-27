#ifndef NEOTEST_CASE_HPP
#define NEOTEST_CASE_HPP

#include"static_string.hpp"
#include"case_dict.h"

namespace neotest{

template<typename StaticString__>
struct Case;

}//namespace neotest

//...: c_str_literal
#define NEOTEST_CASE(...) \
template<> \
struct neotest::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)>{ \
    static void body(void); \
    inline static bool regist_flag=neotest::CaseDict::regist( \
        std::string_view{__VA_ARGS__} \
        ,&neotest::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)>::body \
    ); \
}; \
void neotest::Case<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)>::body(void) \
//

#endif//NEOTEST_CASE_HPP
