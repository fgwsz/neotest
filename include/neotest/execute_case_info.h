#ifndef NEOTEST_EXECUTE_CASE_INFO_H
#define NEOTEST_EXECUTE_CASE_INFO_H

#include<cstddef>//std::size_t

#include<string_view>//std::string_view
#include<optional>//std::optional
#include<chrono>//std::chrono
#include<vector>//std::vector
#include<string>//std::string

#include"runtime_check_failed_error.h"
#include"runtime_assert_failed_exception.h"

namespace neotest{

struct ExecuteCaseInfo{

    std::string_view case_name={};
    std::optional<std::string_view> group_name={};

    std::chrono::system_clock::time_point start_time={};
    std::chrono::system_clock::time_point end_time={};
    std::chrono::nanoseconds duration={};

    std::size_t runtime_check_total=0;
    std::size_t runtime_check_passed=0;
    std::size_t runtime_check_failed=0;

    std::vector<neotest::RuntimeCheckFailedError> runtime_check_errors={};

    std::size_t runtime_assert_total=0;
    std::size_t runtime_assert_passed=0;
    std::size_t runtime_assert_failed=0;

    std::optional<neotest::RuntimeAssertFailedException> runtime_assert_result={};

    std::vector<std::string> runtime_exceptions={};

    enum class State{ Undefined,Passed,Failed,Skipped };

    State state=State::Undefined;

    std::optional<std::string> skip_reason={};

    double check_success_rate()const noexcept{
        return runtime_check_total>0
            ?static_cast<double>(runtime_check_passed)
                /runtime_check_total
            :0.0;
    }
    double assert_success_rate()const noexcept{
        return runtime_assert_total>0
            ?static_cast<double>(runtime_assert_passed)
                /runtime_assert_total
            :0.0;
    }
};

}//namespace neotest

#endif//NEOTEST_EXECUTE_CASE_INFO_H
