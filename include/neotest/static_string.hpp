#ifndef NEOTEST_STATIC_STRING_HPP
#define NEOTEST_STATIC_STRING_HPP

#include<iterator>//std::begin std::end
#include<algorithm>//std::copy
#include<type_traits>//std::remove_cvref_t

namespace neotest{

template<typename CharType__,::std::size_t length__>
struct StaticCStr{
    CharType__ value[length__]{};
    consteval StaticCStr(CharType__ const(&c_str)[length__]){
        std::copy(std::begin(c_str),std::end(c_str),std::begin(value));
    }
    using char_type=CharType__;
    static constexpr auto length=length__;
};

template<StaticCStr static_c_str__>
struct StaticString{
    using char_type=
        typename std::remove_cvref_t<decltype(static_c_str__)>::char_type;
    static constexpr auto size=static_c_str__.length-1;
    static constexpr decltype(auto) value=(static_c_str__.value);
};

}//namespace neotest

#define NEOTEST_MAKE_STATIC_STRING(c_str_literal__) \
    neotest::StaticString<c_str_literal__> \
//

#endif//NEOTEST_STATIC_STRING_HPP
