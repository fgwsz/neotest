#include"runtime_assert.h"

#include"execute_case_info.h"
#include"runtime_assert_failed_exception.h"

namespace neotest{

void runtime_assert(
    neotest::ConditionInfo const& ci
){
    auto& current=neotest::ExecuteCaseInfo::get_current();
    current.runtime_assert_total_increment();
    if(ci.condition){
        current.runtime_assert_passed_increment();
    }else{
        current.runtime_assert_failed_increment();
        throw neotest::RuntimeAssertFailedException(ci.file,ci.line_sv,ci.info);
    }
}

}//namespace neotest
