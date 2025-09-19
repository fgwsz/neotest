#ifndef VNITEST_CASE_HPP
#define VNITEST_CASE_HPP

#include<string_view>//::std::string_view

#include<vnitest/static_string.hpp>
#include<vnitest/case_dict.h>

namespace vnitest::detail{

template<typename StaticString__>
struct Case;

}//namespace vnitest::detail

//...: c_str_literal
#define VNITEST_CASE(...) \
template<> \
struct vnitest::detail::Case<VNITEST_MAKE_STATIC_STRING(__VA_ARGS__)>{ \
    static void body(void); \
    inline static bool regist_flag=::vnitest::CaseDict::regist( \
        ::std::string_view{__VA_ARGS__} \
        ,&::vnitest::detail::Case<VNITEST_MAKE_STATIC_STRING(__VA_ARGS__)> \
            ::body \
    ); \
}; \
void ::vnitest::detail::Case<VNITEST_MAKE_STATIC_STRING(__VA_ARGS__)> \
    ::body(void) \
//

#endif//VNITEST_CASE_HPP
