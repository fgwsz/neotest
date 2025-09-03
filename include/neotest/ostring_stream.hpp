#ifndef NEOTEST_OSTRING_STREAM_HPP
#define NEOTEST_OSTRING_STREAM_HPP

#include<ios>//std::boolalpha
#include<utility>//::std::forward
#include<string>//::std::string
#include<sstream>//::std::ostringstream

namespace neotest{

struct OStringStream{
    OStringStream(void)noexcept
        :oss_({}){
        this->oss_<<::std::boolalpha;
    }
    OStringStream& operator=(OStringStream const&)noexcept=default;
    OStringStream& operator=(OStringStream &&)noexcept=default;
    ~OStringStream(void)noexcept=default;

    template<typename Type__>
    OStringStream& operator<<(Type__&& arg)noexcept{
        this->oss_<<::std::forward<Type__>(arg);
        return *this;
    }
    ::std::string str(void)const noexcept{
        return this->oss_.str();
    }
    ::std::ostringstream oss_;
};

}//namespace neotest

#endif//NEOTEST_OSTRING_STREAM_HPP
