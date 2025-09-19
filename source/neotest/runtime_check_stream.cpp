#include<neotest/runtime_check_stream.hpp>

#include<iostream>//::std::cerr ::std::endl

#include<neotest/runtime_check_failed_error.h>
#include<neotest/execute_case_info.h>
#include<neotest/to_json.h>

namespace neotest{

RuntimeCheckStream::RuntimeCheckStream(::neotest::ConditionInfo const& ci)
noexcept
    :info_(ci)
    ,message_({})
{}
RuntimeCheckStream::~RuntimeCheckStream(void)noexcept{
    ::std::optional<::neotest::RuntimeCheckFailedError> error={};
    if(!this->info_.condition){
        error=::neotest::RuntimeCheckFailedError{
            this->info_.file
            ,this->info_.line
            ,this->info_.info
        };
    }
    if(::neotest::ExecuteCaseInfo::has_current()){//in NEOTEST_CASE
        ::neotest::ExecuteCaseInfo::get_current()
            .runtime_check_total_increment();
    }
    if(!error.has_value()){
        if(::neotest::ExecuteCaseInfo::has_current()){//in NEOTEST_CASE
            ::neotest::ExecuteCaseInfo::get_current()
                .runtime_check_passed_increment();
        }
    }else{
        if(this->message_.has_value()){
            error.value().msg=this->message_.value();
        }
        if(::neotest::ExecuteCaseInfo::has_current()){//in NEOTEST_CASE
            ::neotest::ExecuteCaseInfo::get_current()
                .runtime_check_failed_increment()
                .runtime_check_failed_errors_push_back(error.value());
        }else{//in other function
            ::std::cerr
                <<::neotest::to_json(error.value())
                <<::std::endl;
        }
    }
}

}//namespace neotest
