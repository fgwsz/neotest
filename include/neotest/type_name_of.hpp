#ifndef NEOTEST_TYPE_NAME_OF_HPP
#define NEOTEST_TYPE_NAME_OF_HPP

#include<source_location>//::std::source_location
#include<string_view>//::std::string_view

namespace neotest{

//get type name of <Type__>
//return constexpr ::std::string_view
template<typename Type__>
consteval auto type_name_of(void)noexcept{
#ifndef _MSC_VER
    ::std::string_view ret=::std::source_location::current().function_name();
    auto front_index=ret.find_first_of('=')+1;
    auto back_index=ret.find_last_of(']')-1;
#else
    ::std::string_view ret={__FUNCSIG__};
    auto front_index=ret.find_first_of('<')+1;
    auto back_index=ret.find_last_of('>')-1;
#endif
    front_index=ret.find_first_not_of(' ',front_index);
    back_index=ret.find_last_not_of(' ',back_index);
    return ret.substr(front_index,back_index-front_index+1);
}

}//namespace neotest

#endif//NEOTEST_TYPE_NAME_OF_HPP
