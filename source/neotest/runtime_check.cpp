#include"runtime_check.h"
#include"runtime_check_counter.h"
#include"runtime_failed.h"

namespace neotest{

void runtime_check(
    neotest::ConditionInfo const& ci
)noexcept{
    neotest::runtime_check_count_increment();
    if(ci.condition){
        neotest::runtime_check_passed_count_increment();
    }else{
        neotest::runtime_check_failed_count_increment();
        neotest::runtime_check_failed(ci.file,ci.line,ci.info);
    }
}

}//namespace neotest
