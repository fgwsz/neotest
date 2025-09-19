#include<vnitest/runtime_assert_stream.hpp>

#include<vnitest/runtime_assert_failed_exception.h>
#include<vnitest/execute_case_info.h>

namespace vnitest{

RuntimeAssertStream::RuntimeAssertStream(::vnitest::ConditionInfo const& ci)
noexcept
    :info_(ci)
    ,message_({}){
}
RuntimeAssertStream::~RuntimeAssertStream(void)noexcept(false){
    ::std::optional<::vnitest::RuntimeAssertFailedException> exception={};
    if(!this->info_.condition){
        exception=::vnitest::RuntimeAssertFailedException(
            this->info_.file
            ,this->info_.line
            ,this->info_.info
        );
    }
    if(::vnitest::ExecuteCaseInfo::has_current()){//in VNITEST_CASE
        ::vnitest::ExecuteCaseInfo::get_current()
            .runtime_assert_total_increment();
    }
    if(!exception.has_value()){
        if(::vnitest::ExecuteCaseInfo::has_current()){//in VNITEST_CASE
            ::vnitest::ExecuteCaseInfo::get_current()
                .runtime_assert_passed_increment();
        }
    }else{
        if(::vnitest::ExecuteCaseInfo::has_current()){//in VNITEST_CASE
            ::vnitest::ExecuteCaseInfo::get_current()
                .runtime_assert_failed_increment();
        }
        if(this->message_.has_value()){
            exception.value().set_msg(this->message_.value());
        }
        throw exception.value();
    }
}

}//namespace vnitest
