#include"runtime_assert_stream.hpp"

#include"runtime_assert_failed_exception.h"
#include"execute_case_info.h"

namespace neotest{

RuntimeAssertStream::RuntimeAssertStream(::neotest::ConditionInfo const& ci)
noexcept
    :info_(ci)
    ,message_({}){
}
RuntimeAssertStream::~RuntimeAssertStream(void)noexcept(false){
    ::std::optional<::neotest::RuntimeAssertFailedException> exception={};
    if(!this->info_.condition){
        exception=::neotest::RuntimeAssertFailedException(
            this->info_.file
            ,this->info_.line
            ,this->info_.info
        );
    }
    auto& current=::neotest::ExecuteCaseInfo::get_current();
    current.runtime_assert_total_increment();
    if(!exception.has_value()){
        current.runtime_assert_passed_increment();
    }else{
        current.runtime_assert_failed_increment();
        if(this->message_.has_value()){
            exception.value().set_msg(this->message_.value());
        }
        throw exception.value();
    }
}

}//namespace neotest
