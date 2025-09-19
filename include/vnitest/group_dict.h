#ifndef VNITEST_GROUP_DICT_H
#define VNITEST_GROUP_DICT_H

#include<vector>//::std::vector
#include<variant>//::std::variant
#include<string_view>//::std::string_view

#include<vnitest/ordered_map.hpp>
#include<vnitest/regex.h>

namespace vnitest{

class GroupDict{
public:
    using value_type=
        ::std::vector<::std::variant<::std::string_view,::vnitest::RegEx>>*;
    using dict_type=::vnitest::OrderedMap<::std::string_view,value_type>;
    static dict_type& get(void)noexcept{
        static dict_type group_dict={};
        return group_dict;
    }
    static bool regist(
        ::std::string_view group_name
        ,value_type group_body
    )noexcept{
        if(::vnitest::GroupDict::get().contains(group_name)){
            return false;
        }
        ::vnitest::GroupDict::get().insert(group_name,group_body);
        return true;
    }
};

}//namespace vnitest

#endif//VNITEST_GROUP_DICT_H
