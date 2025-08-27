#include"runtime_check.h"

#include"execute_case_info.h"
#include"runtime_check_failed_error.h"

namespace neotest{

void runtime_check(
    neotest::ConditionInfo const& ci
)noexcept{
    auto& current=neotest::ExecuteCaseInfo::get_current();
    current.runtime_check_total_increment();
    if(ci.condition){
        current.runtime_check_passed_increment();
    }else{
        current.runtime_check_failed_increment();
        current.runtime_check_failed_errors_push_back(
            neotest::RuntimeCheckFailedError{ci.file,ci.line,ci.info}
        );
    }
}

}//namespace neotest
