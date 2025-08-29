#ifndef NEOTEST_SKIP_EXCEPTION_H
#define NEOTEST_SKIP_EXCEPTION_H

#include<exception>//::std::exception
#include<string_view>//::std::string_view
#include<string>//::std::string
#include<optional>//::std::optional

namespace neotest{

class SkipException
    :public ::std::exception{
public:
    SkipException(SkipException const&)noexcept=default;
    SkipException(SkipException &&)noexcept=default;
    SkipException& operator=(SkipException const&)noexcept=default;
    SkipException& operator=(SkipException &&)noexcept=default;
    virtual ~SkipException(void)noexcept=default;

    SkipException(
        ::std::string_view file
        ,::std::string_view line
        ,::std::string const& info
        ,::std::optional<::std::string> const& msg={}
    )noexcept;
    virtual char const* what()const noexcept override;
    ::std::string_view file(void)const noexcept;
    ::std::string_view line(void)const noexcept;
    ::std::string const& info(void)const noexcept;
    bool has_msg(void)const noexcept;
    ::std::string const& msg(void)const noexcept;
    void set_msg(::std::optional<::std::string> const& msg)noexcept;
private:
    ::std::string_view file_,line_;
    ::std::string info_;
    ::std::optional<::std::string> msg_;
};

}//namespace neotest

#endif//NEOTEST_SKIP_EXCEPTION_H
