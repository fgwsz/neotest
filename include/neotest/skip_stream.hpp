#ifndef NEOTEST_SKIP_STREAM_HPP
#define NEOTEST_SKIP_STREAM_HPP

#include<optional>//::std::optional
#include<string>//::std::string
#include<utility>//::std::forward

#include<neotest/source_info.h>
#include<neotest/ostring_stream.hpp>

namespace neotest{

class SkipStream final{
public:
    template<typename Type__>
    SkipStream& operator<<(Type__&& arg)noexcept{
        ::neotest::OStringStream oss={};
        ::std::string str=(oss<<::std::forward<Type__>(arg)).str();
        if(this->message_.has_value()){
            this->message_.value()+=str;
        }else{
            this->message_=str;
        }
        return *this;
    }
    SkipStream(::neotest::SourceInfo const& si)noexcept;
    ~SkipStream(void)noexcept(false);
private:
    ::neotest::SourceInfo info_;
    ::std::optional<::std::string> message_;
};

}//namespace neotest

#endif//NEOTEST_SKIP_STREAM_HPP
