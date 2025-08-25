#ifndef NEOTEST_RUNTIME_CHECK_COUNTER_H
#define NEOTEST_RUNTIME_CHECK_COUNTER_H

#include<cstddef>//std::size_t

namespace neotest{

void runtime_check_count_reset(void)noexcept;
void runtime_check_passed_count_reset(void)noexcept;
void runtime_check_failed_count_reset(void)noexcept;

void runtime_check_count_increment(void)noexcept;
void runtime_check_passed_count_increment(void)noexcept;
void runtime_check_failed_count_increment(void)noexcept;

std::size_t get_runtime_check_count(void)noexcept;
std::size_t get_runtime_check_passed_count(void)noexcept;
std::size_t get_runtime_check_failed_count(void)noexcept;

}//namespace neotest

#endif//NEOTEST_RUNTIME_CHECK_COUNTER_H
