#ifndef NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H
#define NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H

#include<string_view>//std::string_view

namespace neotest{

struct RuntimeCheckFailedError{
    RuntimeCheckFailedError(
        std::string_view file
        ,std::string_view line
        ,std::string_view info
    )noexcept{
        this->file=file;
        this->line=line;
        this->info=info;
    }
    std::string_view file,line,info;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_CHECK_FAILED_ERROR_H
