#ifndef NEOTEST_EXECUTE_H
#define NEOTEST_EXECUTE_H

#include<string_view>//::std::string_view
#include<vector>//::std::vector
#include<regex>//::std::regex

#include"execute_case_info.h"
#include"execute_group_info.h"

namespace neotest{

::neotest::ExecuteCaseInfo execute_case(
    ::std::string_view case_name
)noexcept;

::std::vector<::neotest::ExecuteCaseInfo> execute_case(
    ::std::regex const& case_name_regex
)noexcept;

::neotest::ExecuteGroupInfo execute_group(
    ::std::string_view group_name
)noexcept;

::std::vector<::neotest::ExecuteGroupInfo> execute_group(
    ::std::regex const& group_name_regex
)noexcept;

}//namespace neotest

#endif//NEOTEST_EXECUTE_H
