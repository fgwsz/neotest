#ifndef VNITEST_EXECUTE_GROUP_INFO_H
#define VNITEST_EXECUTE_GROUP_INFO_H

#include<cstddef>//::std::size_t

#include<string_view>//std:;string_view
#include<vector>//::std::vector
#include<variant>//::std::variant
#include<tuple>//::std::tuple

#include<vnitest/timer.h>
#include<vnitest/execute_case_info.h>

namespace vnitest{

class ExecuteGroupInfo{
public:
    ExecuteGroupInfo(ExecuteGroupInfo const&)=default;
    ExecuteGroupInfo(ExecuteGroupInfo &&)=default;
    ExecuteGroupInfo& operator=(ExecuteGroupInfo const&)=default;
    ExecuteGroupInfo& operator=(ExecuteGroupInfo &&)=default;
    ~ExecuteGroupInfo(void)=default;

    explicit ExecuteGroupInfo(::std::string_view name="")noexcept;
    //group name
    ExecuteGroupInfo& set_name(::std::string_view name)noexcept;
    ::std::string_view get_name(void)const noexcept;
    //execute time info
    ExecuteGroupInfo& execute_start(void)noexcept;
    ExecuteGroupInfo& execute_stop(void)noexcept;
    double get_duration_ns(void)const noexcept;
    ::std::string get_duration_string(void)const noexcept;
    //case
    ExecuteGroupInfo& case_total_increment(void)noexcept;
    ExecuteGroupInfo& case_passed_increment(void)noexcept;
    ExecuteGroupInfo& case_failed_increment(void)noexcept;
    ExecuteGroupInfo& case_skipped_increment(void)noexcept;
    ExecuteGroupInfo& case_undefined_increment(void)noexcept;
    ::std::size_t get_case_total(void)const noexcept;
    ::std::size_t get_case_passed(void)const noexcept;
    ::std::size_t get_case_failed(void)const noexcept;
    ::std::size_t get_case_skipped(void)const noexcept;
    ::std::size_t get_case_undefined(void)const noexcept;
    double get_case_passed_rate(void)const noexcept;
    //state
    enum class State{ Undefined,Passed,Failed,Skipped };
    ExecuteGroupInfo::State get_state(void)const noexcept;
    bool is_passed(void)const noexcept;
    bool is_failed(void)const noexcept;
    bool is_skipped(void)const noexcept;
    bool is_undefined(void)const noexcept;
    //data
    using case_regex_info_type=::std::tuple<
        ::std::string_view
        ,::std::vector<::vnitest::ExecuteCaseInfo>
    >;
    using element_type=::std::variant<
        ::vnitest::ExecuteCaseInfo
        ,case_regex_info_type
    >;
    ExecuteGroupInfo& data_push_back(
        ::std::string_view case_name
        ,::vnitest::ExecuteCaseInfo const& case_info
    )noexcept;
    ExecuteGroupInfo& data_push_back(
        ::std::string_view case_regex_pattern
        ,::std::vector<::vnitest::ExecuteCaseInfo> const& case_regex_info
    )noexcept;
    ::std::vector<element_type>const& get_data(void)const noexcept;
private:
    ::std::string_view name_;
    ::vnitest::Timer timer_;
    ::std::size_t case_total_;
    ::std::size_t case_passed_;
    ::std::size_t case_failed_;
    ::std::size_t case_skipped_;
    ::std::size_t case_undefined_;
    ::std::vector<element_type> data_;
};

}//namespace vnitest

#endif//VNITEST_EXECUTE_GROUP_INFO_H
