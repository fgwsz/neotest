#ifndef NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H
#define NEOTEST_RUNTIME_ASSERT_FAILED_EXCEPTION_H

#include<exception>//std::exception

namespace neotest{

class RuntimeAssertFailedException
    :public std::exception{
public:
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
