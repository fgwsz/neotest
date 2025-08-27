#include"runtime_assert_failed_exception.h"

#include<format>//std::format

namespace neotest{

RuntimeAssertFailedException::RuntimeAssertFailedException(
    std::string_view file
    ,std::string_view line
    ,std::string const& info
)noexcept
:file_(file),line_(line),info_(info),what_({}){
    this->what_=std::format(
        "{}({}): {}"
        ,this->file_
        ,this->line_
        ,this->info_
    );
}
char const* RuntimeAssertFailedException::what()const noexcept{
    return this->what_.c_str();
}
std::string_view RuntimeAssertFailedException::file(void)const noexcept{
    return this->file_;
}
std::string_view RuntimeAssertFailedException::line(void)const noexcept{
    return this->line_;
}
std::string const& RuntimeAssertFailedException::info(void)const noexcept{
    return this->info_;
}

}//namespace neotest
