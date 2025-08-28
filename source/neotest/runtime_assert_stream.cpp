#include"runtime_assert_stream.hpp"

#include"execute_case_info.h"

namespace neotest{

RuntimeAssertStream::RuntimeAssertStream(neotest::ConditionInfo const& ci)noexcept
    :exception_({})
    ,message_({}){
    if(!ci.condition){
        this->exception_=
            neotest::RuntimeAssertFailedException(ci.file,ci.line,ci.info);
    }
}
RuntimeAssertStream::~RuntimeAssertStream(void)noexcept(false){
    auto& current=neotest::ExecuteCaseInfo::get_current();
    current.runtime_assert_total_increment();
    if(!this->exception_.has_value()){
        current.runtime_assert_passed_increment();
    }else{
        current.runtime_assert_failed_increment();
        if(this->message_.has_value()){
            this->exception_.value().set_msg(this->message_.value());
        }
        throw this->exception_.value();
    }
}

}//namespace neotest
