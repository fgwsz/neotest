#ifndef NEOTEST_RUNTIME_ASSERT_STREAM_HPP
#define NEOTEST_RUNTIME_ASSERT_STREAM_HPP

#include<optional>//::std::optional
#include<string>//::std::string
#include<utility>//::std::forward

#include"condition_info.h"
#include"ostring_stream.hpp"

namespace neotest{

class RuntimeAssertStream final{
public:
    template<typename Type__>
    RuntimeAssertStream& operator<<(Type__&& arg)noexcept{
        ::neotest::OStringStream oss={};
        ::std::string str=(oss<<::std::forward<Type__>(arg)).str();
        if(this->message_.has_value()){
            this->message_.value()+=str;
        }else{
            this->message_=str;
        }
        return *this;
    }
    RuntimeAssertStream(::neotest::ConditionInfo const& ci)noexcept;
    ~RuntimeAssertStream(void)noexcept(false);
private:
    ::neotest::ConditionInfo info_;
    ::std::optional<::std::string> message_;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_ASSERT_STREAM_HPP
