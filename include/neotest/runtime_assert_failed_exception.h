#ifndef NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H
#define NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H

#include<exception>//std::exception
#include<string_view>//std::string_view
#include<string>//std::string
#include<optional>//std::optional

namespace neotest{

class RuntimeAssertFailedException
    :public std::exception{
public:
    RuntimeAssertFailedException(RuntimeAssertFailedException const&)noexcept
        =default;
    RuntimeAssertFailedException(RuntimeAssertFailedException &&)noexcept
        =default;
    RuntimeAssertFailedException&
        operator=(RuntimeAssertFailedException const&)noexcept=default;
    RuntimeAssertFailedException&
        operator=(RuntimeAssertFailedException &&)noexcept=default;
    virtual ~RuntimeAssertFailedException(void)noexcept=default;

    RuntimeAssertFailedException(
        std::string_view file
        ,std::string_view line
        ,std::string const& info
        ,std::optional<std::string> const& msg={}
    )noexcept;
    virtual char const* what()const noexcept override;
    std::string_view file(void)const noexcept;
    std::string_view line(void)const noexcept;
    std::string const& info(void)const noexcept;
    bool has_msg(void)const noexcept;
    std::string const& msg(void)const noexcept;
    void set_msg(std::optional<std::string> const& msg)noexcept;
private:
    std::string_view file_,line_;
    std::string info_;
    std::optional<std::string> msg_;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H
