#ifndef NEOTEST_RUNTIME_FAILED_H
#define NEOTEST_RUNTIME_FAILED_H

namespace neotest{

void runtime_check_failed(
    std::string_view file
    ,std::string_view line
    ,std::string_view info
)noexcept;

void runtime_assert_failed(
    std::string_view file
    ,std::string_view line
    ,std::string_view info
);

}//namespace neotest

#endif//NEOTEST_RUNTIME_FAILED_H
