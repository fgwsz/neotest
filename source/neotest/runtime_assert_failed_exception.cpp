#include"runtime_assert_failed_exception.h"

#include<format>//::std::format

namespace neotest{

RuntimeAssertFailedException::RuntimeAssertFailedException(
    ::std::string_view file
    ,::std::string_view line
    ,::std::string const& info
    ,::std::optional<::std::string> const& msg
)noexcept
:file_(file),line_(line),info_(info),msg_(msg)
{}
char const* RuntimeAssertFailedException::what(void)const noexcept{
    static ::std::string ret;
    ret=::std::format(
        "[FILE] {} [LINE] {} [INFO] {}"
        ,this->file_
        ,this->line_
        ,this->info_
    );
    if(this->msg_.has_value()){
        ret+=::std::format(" [MSG] {}",this->msg_.value());
    }
    return ret.c_str();
}
::std::string_view RuntimeAssertFailedException::file(void)const noexcept{
    return this->file_;
}
::std::string_view RuntimeAssertFailedException::line(void)const noexcept{
    return this->line_;
}
::std::string const& RuntimeAssertFailedException::info(void)const noexcept{
    return this->info_;
}
bool RuntimeAssertFailedException::has_msg(void)const noexcept{
    return this->msg_.has_value();
}
::std::string const& RuntimeAssertFailedException::msg(void)const noexcept{
    return this->msg_.value();
}
void RuntimeAssertFailedException::set_msg(
    ::std::optional<::std::string> const& msg
)noexcept{
    this->msg_=msg;
}

}//namespace neotest
