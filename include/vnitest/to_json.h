#ifndef VNITEST_TO_JSON_H
#define VNITEST_TO_JSON_H

#include<cstddef>//::std::size_t

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<vector>//::std::vector

#include<vnitest/runtime_check_failed_error.h>
#include<vnitest/runtime_assert_failed_exception.h>
#include<vnitest/skip_exception.h>
#include<vnitest/execute_case_info.h>
#include<vnitest/execute_group_info.h>

namespace vnitest{

inline static constexpr ::std::size_t default_tab_width=4;

::std::string to_json(
    bool condition
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::string_view sv
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::string const& str
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::size_t size
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    double number
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::vnitest::RuntimeCheckFailedError const& error
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::vnitest::RuntimeCheckFailedError>const& errors
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::vnitest::RuntimeAssertFailedException const& exception
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::vnitest::SkipException const& exception
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::vnitest::ExecuteCaseInfo const& ei
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::vnitest::ExecuteCaseInfo> const& ei_vec
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::vnitest::ExecuteGroupInfo const& ei
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::vnitest::ExecuteGroupInfo> const& ei_vec
    ,::std::size_t tab_width=::vnitest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;

}//namespace vnitest

#endif//VNITEST_TO_JSON_H
