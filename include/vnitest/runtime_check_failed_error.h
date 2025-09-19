#ifndef VNITEST_RUNTIME_CHECK_FAILED_ERROR_H
#define VNITEST_RUNTIME_CHECK_FAILED_ERROR_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<optional>//::std::optional

namespace vnitest{

struct RuntimeCheckFailedError{
    ::std::string_view file,line;
    ::std::string info;
    ::std::optional<::std::string> msg;
};

}//namespace vnitest

#endif//VNITEST_RUNTIME_CHECK_FAILED_ERROR_H
