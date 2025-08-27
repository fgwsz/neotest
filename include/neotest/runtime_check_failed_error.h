#ifndef NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H
#define NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H

#include<string_view>//std::string_view
#include<string>//std::string

namespace neotest{

struct RuntimeCheckFailedError{
    std::string_view file,line;
    std::string info;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H
