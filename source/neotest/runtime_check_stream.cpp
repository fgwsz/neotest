#include"runtime_check_stream.hpp"

#include"runtime_check_failed_error.h"
#include"execute_case_info.h"

namespace neotest{

RuntimeCheckStream::RuntimeCheckStream(neotest::ConditionInfo const& ci)noexcept
    :info_(ci)
    ,message_({})
{}
RuntimeCheckStream::~RuntimeCheckStream(void)noexcept{
    std::optional<neotest::RuntimeCheckFailedError> error={};
    if(!this->info_.condition){
        error=neotest::RuntimeCheckFailedError{
            this->info_.file
            ,this->info_.line
            ,this->info_.info
        };
    }
    auto& current=neotest::ExecuteCaseInfo::get_current();
    current.runtime_check_total_increment();
    if(!error.has_value()){
        current.runtime_check_passed_increment();
    }else{
        current.runtime_check_failed_increment();
        if(this->message_.has_value()){
            error.value().msg=this->message_.value();
        }
        current.runtime_check_failed_errors_push_back(
            error.value()
        );
    }
}

}//namespace neotest
