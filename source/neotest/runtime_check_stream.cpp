#include"runtime_check_stream.hpp"

#include<string>//::std::string
#include<format>//::std::format
#include<iostream>//::std::cerr ::std::endl

#include"runtime_check_failed_error.h"
#include"execute_case_info.h"
#include"to_json.h"

namespace neotest{

namespace detail{

::std::string runtime_check_failed_error_to_string(
    ::neotest::RuntimeCheckFailedError const& error
)noexcept{
    ::std::string ret=::std::format(
        "[FILE] {} [LINE] {} [INFO] {}"
        ,error.file
        ,error.line
        ,error.info
    );
    if(error.msg.has_value()){
        ret+=::std::format(" [MSG] {}",error.msg.value());
    }
    return ret;
}

}//namespace neotest::detail


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
                //<<::neotest::detail::runtime_check_failed_error_to_string(
                //        error.value()
                //    )
                <<::neotest::value_to_json(error.value())
                <<::std::endl;
        }
    }
}

}//namespace neotest
