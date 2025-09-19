#ifndef VNITEST_RUNTIME_CHECK_STREAM_HPP
#define VNITEST_RUNTIME_CHECK_STREAM_HPP

#include<optional>//::std::optional
#include<string>//::std::string
#include<utility>//::std::forward

#include<vnitest/condition_info.h>
#include<vnitest/ostring_stream.hpp>

namespace vnitest{

class RuntimeCheckStream final{
public:
    template<typename Type__>
    RuntimeCheckStream& operator<<(Type__&& arg)noexcept{
        ::vnitest::OStringStream oss={};
        ::std::string str=(oss<<::std::forward<Type__>(arg)).str();
        if(this->message_.has_value()){
            this->message_.value()+=str;
        }else{
            this->message_=str;
        }
        return *this;
    }
    RuntimeCheckStream(::vnitest::ConditionInfo const& ci)noexcept;
    ~RuntimeCheckStream(void)noexcept;
private:
    ::vnitest::ConditionInfo info_;
    ::std::optional<::std::string> message_;
};

}//namespace vnitest

#endif//VNITEST_RUNTIME_CHECK_STREAM_HPP
