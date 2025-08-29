#include"skip_exception.h"

#include<format>//::std::format

namespace neotest{

SkipException::SkipException(
    ::std::string_view file
    ,::std::string_view line
    ,::std::string const& info
    ,::std::optional<::std::string> const& msg
)noexcept
:file_(file),line_(line),info_(info),msg_(msg)
{}
char const* SkipException::what(void)const noexcept{
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
::std::string_view SkipException::file(void)const noexcept{
    return this->file_;
}
::std::string_view SkipException::line(void)const noexcept{
    return this->line_;
}
::std::string const& SkipException::info(void)const noexcept{
    return this->info_;
}
bool SkipException::has_msg(void)const noexcept{
    return this->msg_.has_value();
}
::std::string const& SkipException::msg(void)const noexcept{
    return this->msg_.value();
}
void SkipException::set_msg(
    ::std::optional<::std::string> const& msg
)noexcept{
    this->msg_=msg;
}

}//namespace neotest
