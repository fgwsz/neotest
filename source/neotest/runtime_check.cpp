#include"runtime_check.h"
#include"runtime_check_counter.h"

void runtime_check_failed(
    neotest::ConditionInfo const& ci
)noexcept{}

namespace neotest{

void runtime_check(
    neotest::ConditionInfo const& ci
)noexcept{
    neotest::runtime_check_count_increment();
    if(ci.condition){
        neotest::runtime_check_passed_count_increment();
    }else{
        neotest::runtime_check_failed_count_increment();
        runtime_check_failed(ci);
    }
}

}//namespace neotest
