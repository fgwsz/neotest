#ifndef NEOTEST_CASE_HPP
#define NEOTEST_CASE_HPP

#include<string_view>//std::string_view

#include"ordered_map.hpp"
#include"static_string.hpp"

namespace neotest{

template<typename StaticString__>
struct Case;

static neotest::OrderedMap<std::string_view,void(*)(void)> case_dict={};

bool case_register(
    std::string_view case_name
    ,void(*case_body)(void)
)noexcept{
    if(neotest::case_dict.contains(case_name)){
        return false;
    }
    neotest::case_dict.insert(case_name,case_body);
    return true;
}

}//namespace neotest

#define NEOTEST_CASE(c_str_literal__) \
template<> \
struct neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>{ \
    static void body(void); \
    inline static bool regist_flag=neotest::case_register( \
        std::string_view{c_str_literal__} \
        ,&neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>::body \
    ); \
}; \
void neotest::Case<NEOTEST_MAKE_STATIC_STRING(c_str_literal__)>::body(void) \
//

#endif//NEOTEST_CASE_HPP
