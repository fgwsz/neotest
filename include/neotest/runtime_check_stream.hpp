#ifndef NEOTEST_RUNTIME_CHECK_STREAM_HPP
#define NEOTEST_RUNTIME_CHECK_STREAM_HPP

#include<optional>//std::optional
#include<string>//std::string
#include<sstream>//std::ostringstream
#include<utility>//std::forward

#include"condition_info.h"
#include"runtime_check_failed_error.h"

namespace neotest{

class RuntimeCheckStream final{
public:
    template<typename Type__>
    RuntimeCheckStream& operator<<(Type__&& arg)noexcept{
        std::string str=
            (std::ostringstream{}<<std::forward<Type__>(arg)).str();
        if(this->message_.has_value()){
            this->message_.value()+=str;
        }else{
            this->message_=str;
        }
        return *this;
    }
    RuntimeCheckStream(neotest::ConditionInfo const& ci)noexcept;
    ~RuntimeCheckStream(void)noexcept;
private:
    std::optional<neotest::RuntimeCheckFailedError> error_;
    std::optional<std::string> message_;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_CHECK_STREAM_HPP
