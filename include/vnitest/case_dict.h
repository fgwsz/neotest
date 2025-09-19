#ifndef VNITEST_CASE_DICT_H
#define VNITEST_CASE_DICT_H

#include<string_view>//::std::string_view

#include<vnitest/ordered_map.hpp>

namespace vnitest{

class CaseDict{
public:
    using dict_type=::vnitest::OrderedMap<::std::string_view,void(*)(void)>;
    static dict_type& get(void)noexcept{
        static dict_type case_dict={};
        return case_dict;
    }
    static bool regist(
        ::std::string_view case_name
        ,void(*case_body)(void)
    )noexcept{
        if(::vnitest::CaseDict::get().contains(case_name)){
            return false;
        }
        ::vnitest::CaseDict::get().insert(case_name,case_body);
        return true;
    }
};

}//namespace vnitest

#endif//VNITEST_CASE_DICT_H
