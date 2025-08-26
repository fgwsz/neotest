#include"runtime_assert.h"

#include"runtime_failed.h"

namespace neotest{

void runtime_assert(
    neotest::ConditionInfo const& ci
)noexcept{
    if(!ci.condition){
        neotest::runtime_assert_failed(ci.file,ci.line_sv,ci.info);
    }
}

}//namespace neotest
