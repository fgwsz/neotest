#ifndef NEOTEST_TO_JSON_H
#define NEOTEST_TO_JSON_H

#include<cstddef>//::std::size_t

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<vector>//::std::vector

#include<neotest/runtime_check_failed_error.h>
#include<neotest/runtime_assert_failed_exception.h>
#include<neotest/skip_exception.h>
#include<neotest/execute_case_info.h>
#include<neotest/execute_group_info.h>

namespace neotest{

inline static constexpr ::std::size_t default_tab_width=4;

::std::string to_json(
    bool condition
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::string_view sv
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::string const& str
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::size_t size
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    double number
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::neotest::RuntimeCheckFailedError const& error
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::neotest::RuntimeCheckFailedError>const& errors
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::neotest::RuntimeAssertFailedException const& exception
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::neotest::SkipException const& exception
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::neotest::ExecuteCaseInfo const& ei
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::neotest::ExecuteCaseInfo> const& ei_vec
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::neotest::ExecuteGroupInfo const& ei
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;
::std::string to_json(
    ::std::vector<::neotest::ExecuteGroupInfo> const& ei_vec
    ,::std::size_t tab_width=::neotest::default_tab_width
    ,::std::size_t current_tab_number=0
)noexcept;

}//namespace neotest

#endif//NEOTEST_TO_JSON_H
