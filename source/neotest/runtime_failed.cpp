#include"runtime_failed.h"

#include"runtime_assert_failed_exception.h"

namespace neotest{

void runtime_check_failed(
    std::string_view file
    ,std::string_view line
    ,std::string_view info
)noexcept{
    //TODO
}

void runtime_assert_failed(
    std::string_view file
    ,std::string_view line
    ,std::string_view info
){
    throw neotest::RuntimeAssertFailedException(file,line,info);
}

}//namespace neotest
