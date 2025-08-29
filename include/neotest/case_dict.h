#ifndef NEOTEST_CASE_DICT_H
#define NEOTEST_CASE_DICT_H

#include<string_view>//::std::string_view

#include"ordered_map.hpp"

namespace neotest{

class CaseDict{
public:
    using dict_type=::neotest::OrderedMap<::std::string_view,void(*)(void)>;
    static dict_type& get(void)noexcept{
        static dict_type case_dict={};
        return case_dict;
    }
    static bool regist(
        ::std::string_view case_name
        ,void(*case_body)(void)
    )noexcept{
        if(::neotest::CaseDict::get().contains(case_name)){
            return false;
        }
        ::neotest::CaseDict::get().insert(case_name,case_body);
        return true;
    }
};

}//namespace neotest

#endif//NEOTEST_CASE_DICT_H
