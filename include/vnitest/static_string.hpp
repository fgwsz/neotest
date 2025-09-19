#ifndef VNITEST_STATIC_STRING_HPP
#define VNITEST_STATIC_STRING_HPP

#include<iterator>//::std::begin ::std::end
#include<algorithm>//::std::copy
#include<type_traits>//::std::remove_cvref_t

namespace vnitest{

template<typename CharType__,::std::size_t length__>
struct StaticCStr{
    CharType__ value[length__]{};
    consteval StaticCStr(CharType__ const(&c_str)[length__]){
        ::std::copy(
            ::std::begin(c_str),::std::end(c_str),::std::begin(value)
        );
    }
    using char_type=CharType__;
    static constexpr auto length=length__;
};

template<StaticCStr static_c_str__>
struct StaticString{
    using char_type=
        typename ::std::remove_cvref_t<decltype(static_c_str__)>::char_type;
    static constexpr auto size=static_c_str__.length-1;
    static constexpr decltype(auto) value=(static_c_str__.value);
};

}//namespace vnitest

//...: c_str_literal
#define VNITEST_MAKE_STATIC_STRING(...) \
    ::vnitest::StaticString<__VA_ARGS__> \
//

#endif//VNITEST_STATIC_STRING_HPP
