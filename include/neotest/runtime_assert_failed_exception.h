#ifndef NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H
#define NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H

#include<exception>//std::exception
#include<string_view>//std::string_view
#include<string>//std::string

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
        ,std::string_view info
    )noexcept;
    virtual char const* what()const noexcept override;
    std::string_view file(void)const noexcept;
    std::string_view line(void)const noexcept;
    std::string_view info(void)const noexcept;
private:
    std::string_view file_,line_,info_;
    std::string what_;
};

}//namespace neotest

#endif//NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H
