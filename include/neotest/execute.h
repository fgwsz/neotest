#ifndef NEOTEST_EXECUTE_H
#define NEOTEST_EXECUTE_H

#include<string_view>//std::string_view

#include"execute_case_info.h"

namespace neotest{

neotest::ExecuteCaseInfo execute_case(
    std::string_view case_name
)noexcept;

}//namespace neotest

#endif//NEOTEST_EXECUTE_H
