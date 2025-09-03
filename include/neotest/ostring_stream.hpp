#ifndef NEOTEST_OSTRING_STREAM_HPP
#define NEOTEST_OSTRING_STREAM_HPP

#include<ios>//std::boolalpha
#include<utility>//::std::forward
#include<string>//::std::string
#include<sstream>//::std::ostringstream

namespace neotest{

class OStringStream{
public:
    OStringStream(void)noexcept
        :data_({}){
        this->data_<<::std::boolalpha;
    }
    OStringStream& operator=(OStringStream const&)noexcept=default;
    OStringStream& operator=(OStringStream &&)noexcept=default;
    ~OStringStream(void)noexcept=default;

    template<typename Type__>requires requires{
        ::std::ostringstream{}<<Type__{};
    }
    OStringStream& operator<<(Type__&& arg)noexcept{
        this->data_<<::std::forward<Type__>(arg);
        return *this;
    }
    ::std::string str(void)const noexcept{
        return this->data_.str();
    }
private:
    ::std::ostringstream data_;
};

}//namespace neotest

#endif//NEOTEST_OSTRING_STREAM_HPP
