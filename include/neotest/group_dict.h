#ifndef NEOTEST_GROUP_DICT_H
#define NEOTEST_GROUP_DICT_H

#include<vector>//::std::vector
#include<variant>//::std::variant
#include<string_view>//::std::string_view

#include"ordered_map.hpp"
#include"regex.h"

namespace neotest{

class GroupDict{
public:
    using value_type=
        ::std::vector<::std::variant<::std::string_view,::neotest::RegEx>>*;
    using dict_type=::neotest::OrderedMap<::std::string_view,value_type>;
    static dict_type& get(void)noexcept{
        static dict_type group_dict={};
        return group_dict;
    }
    static bool regist(
        ::std::string_view group_name
        ,value_type group_body
    )noexcept{
        if(::neotest::GroupDict::get().contains(group_name)){
            return false;
        }
        ::neotest::GroupDict::get().insert(group_name,group_body);
        return true;
    }
};

}//namespace neotest

#endif//NEOTEST_GROUP_DICT_H
