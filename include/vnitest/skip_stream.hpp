#ifndef VNITEST_SKIP_STREAM_HPP
#define VNITEST_SKIP_STREAM_HPP

#include<optional>//::std::optional
#include<string>//::std::string
#include<utility>//::std::forward

#include<vnitest/source_info.h>
#include<vnitest/ostring_stream.hpp>

namespace vnitest{

class SkipStream final{
public:
    template<typename Type__>
    SkipStream& operator<<(Type__&& arg)noexcept{
        ::vnitest::OStringStream oss={};
        ::std::string str=(oss<<::std::forward<Type__>(arg)).str();
        if(this->message_.has_value()){
            this->message_.value()+=str;
        }else{
            this->message_=str;
        }
        return *this;
    }
    SkipStream(::vnitest::SourceInfo const& si)noexcept;
    ~SkipStream(void)noexcept(false);
private:
    ::vnitest::SourceInfo info_;
    ::std::optional<::std::string> message_;
};

}//namespace vnitest

#endif//VNITEST_SKIP_STREAM_HPP
