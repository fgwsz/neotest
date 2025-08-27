#ifndef NEOTEST_CASE_HPP
#define NEOTEST_CASE_HPP

#include"static_string.hpp"
#include"case_dict.h"

namespace neotest{

template<typename StaticString__>
struct Case;

}//namespace neotest

#define NEOTEST_CASE(c_str_literal__) \
template<> \
struct neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>{ \
    static void body(void); \
    inline static bool regist_flag=neotest::CaseDict::regist( \
        std::string_view{c_str_literal__} \
        ,&neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>::body \
    ); \
}; \
void neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>::body(void) \
//

#endif//NEOTEST_CASE_HPP
