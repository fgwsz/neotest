#include"runtime_check_stream.hpp"

#include"execute_case_info.h"

namespace neotest{

RuntimeCheckStream::RuntimeCheckStream(neotest::ConditionInfo const& ci)noexcept
    :error_({})
    ,message_({}){
    if(!ci.condition){
        this->error_=
            neotest::RuntimeCheckFailedError{ci.file,ci.line,ci.info};
    }
}
RuntimeCheckStream::~RuntimeCheckStream(void)noexcept{
    auto& current=neotest::ExecuteCaseInfo::get_current();
    current.runtime_check_total_increment();
    if(!this->error_.has_value()){
        current.runtime_check_passed_increment();
    }else{
        current.runtime_check_failed_increment();
        if(this->message_.has_value()){
            this->error_.value().msg=this->message_.value();
        }
        current.runtime_check_failed_errors_push_back(
            this->error_.value()
        );
    }
}

}//namespace neotest
