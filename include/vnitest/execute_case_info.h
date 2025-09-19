#ifndef VNITEST_EXECUTE_CASE_INFO_H
#define VNITEST_EXECUTE_CASE_INFO_H

#include<cstddef>//::std::size_t

#include<string_view>//::std::string_view
#include<optional>//::std::optional
#include<vector>//::std::vector
#include<string>//::std::string
#include<functional>//::std::function

#include<vnitest/timer.h>
#include<vnitest/runtime_check_failed_error.h>
#include<vnitest/runtime_assert_failed_exception.h>
#include<vnitest/skip_exception.h>

namespace vnitest{

class ExecuteCaseInfo{
public:
    ExecuteCaseInfo(ExecuteCaseInfo const&)=default;
    ExecuteCaseInfo(ExecuteCaseInfo &&)=default;
    ExecuteCaseInfo& operator=(ExecuteCaseInfo const&)=default;
    ExecuteCaseInfo& operator=(ExecuteCaseInfo &&)=default;
    ~ExecuteCaseInfo(void)=default;

    explicit ExecuteCaseInfo(::std::string_view case_name="")noexcept;
    //case name
    ExecuteCaseInfo& set_case_name(::std::string_view case_name)noexcept;
    ::std::string_view get_case_name(void)const noexcept;
    //group name
    bool has_group_name(void)const noexcept;
    ExecuteCaseInfo& set_group_name(::std::string_view group_name)noexcept;
    ::std::string_view get_group_name(void)const noexcept;
    //execute time info
    ExecuteCaseInfo& execute_start(void)noexcept;
    ExecuteCaseInfo& execute_stop(void)noexcept;
    double get_duration_ns(void)const noexcept;
    ::std::string get_duration_string(void)const noexcept;
    //runtime check
    ExecuteCaseInfo& runtime_check_total_increment(void)noexcept;
    ExecuteCaseInfo& runtime_check_passed_increment(void)noexcept;
    ExecuteCaseInfo& runtime_check_failed_increment(void)noexcept;
    ::std::size_t get_runtime_check_total(void)const noexcept;
    ::std::size_t get_runtime_check_passed(void)const noexcept;
    ::std::size_t get_runtime_check_failed(void)const noexcept;
    double get_runtime_check_passed_rate(void)const noexcept;
    //runtime check failed errors
    bool has_runtime_check_failed_errors(void)const noexcept;
    ExecuteCaseInfo& runtime_check_failed_errors_push_back(
        ::vnitest::RuntimeCheckFailedError const& error
    )noexcept;
    ExecuteCaseInfo const& runtime_check_failed_errors_foreach(
        ::std::function<void(::vnitest::RuntimeCheckFailedError const&)>const&
            func
    )const noexcept;
    ::std::vector<::vnitest::RuntimeCheckFailedError> const&
        get_runtime_check_errors(void)const noexcept;
    //runtime assert
    ExecuteCaseInfo& runtime_assert_total_increment(void)noexcept;
    ExecuteCaseInfo& runtime_assert_passed_increment(void)noexcept;
    ExecuteCaseInfo& runtime_assert_failed_increment(void)noexcept;
    ::std::size_t get_runtime_assert_total(void)const noexcept;
    ::std::size_t get_runtime_assert_passed(void)const noexcept;
    ::std::size_t get_runtime_assert_failed(void)const noexcept;
    double get_runtime_assert_passed_rate(void)const noexcept;
    //runtime assert failed exception
    ExecuteCaseInfo& set_runtime_assert_failed_exception(
        ::vnitest::RuntimeAssertFailedException const& exception
    )noexcept;
    bool has_runtime_assert_failed_exception(void)const noexcept;
    ::vnitest::RuntimeAssertFailedException const&
    get_runtime_assert_failed_exception(void)const noexcept;
    //runtime exception
    bool has_runtime_exception(void)const noexcept;
    ExecuteCaseInfo& set_runtime_exception(
        ::std::string const& exception_what
    )noexcept;
    ::std::string const& get_runtime_exception(void)const noexcept;
    //state
    enum class State{ Undefined,Passed,Failed,Skipped };
    ExecuteCaseInfo::State get_state(void)const noexcept;
    bool is_passed(void)const noexcept;
    bool is_failed(void)const noexcept;
    bool is_skipped(void)const noexcept;
    bool is_undefined(void)const noexcept;
    //skip
    ExecuteCaseInfo& set_skip(::vnitest::SkipException const& se)noexcept;
    bool has_skip(void)const noexcept;
    ::vnitest::SkipException const& get_skip(void)const noexcept;
    //current
    static void set_current(ExecuteCaseInfo& info)noexcept;
    static ExecuteCaseInfo& get_current(void)noexcept;
    static bool has_current(void)noexcept;
    static void reset_current(void)noexcept;
private:
    ::std::string_view case_name_;
    ::std::optional<::std::string_view> group_name_;
    ::vnitest::Timer timer_;
    ::std::size_t runtime_check_total_;
    ::std::size_t runtime_check_passed_;
    ::std::size_t runtime_check_failed_;
    ::std::vector<::vnitest::RuntimeCheckFailedError>
        runtime_check_failed_errors_;
    ::std::size_t runtime_assert_total_;
    ::std::size_t runtime_assert_passed_;
    ::std::size_t runtime_assert_failed_;
    ::std::optional<::vnitest::RuntimeAssertFailedException>
        runtime_assert_failed_exception_;
    ::std::optional<::std::string> runtime_exception_;
    ::std::optional<::vnitest::SkipException> skip_exception_;
    static ExecuteCaseInfo* current_;
};

}//namespace vnitest

#endif//VNITEST_EXECUTE_CASE_INFO_H
