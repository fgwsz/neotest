#ifndef NEOTEST_SKIP_STREAM_HPP
#define NEOTEST_SKIP_STREAM_HPP

#include<optional>//::std::optional
#include<string>//::std::string
#include<sstream>//::std::ostringstream
#include<utility>//::std::forward

#include"source_info.h"

namespace neotest{

class SkipStream final{
public:
    template<typename Type__>
    SkipStream& operator<<(Type__&& arg)noexcept{
        ::std::string str=
            (::std::ostringstream{}<<::std::forward<Type__>(arg)).str();
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
