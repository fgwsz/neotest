#include"runtime_check_counter.h"

namespace neotest{

static std::size_t runtime_check_count=0;
static std::size_t runtime_check_passed_count=0;
static std::size_t runtime_check_failed_count=0;

void runtime_check_count_reset(void)noexcept{
    runtime_check_count=0;
}
void runtime_check_passed_count_reset(void)noexcept{
    runtime_check_passed_count=0;
}
void runtime_check_failed_count_reset(void)noexcept{
    runtime_check_failed_count=0;
}
void runtime_check_count_increment(void)noexcept{
    ++runtime_check_count;
}
void runtime_check_passed_count_increment(void)noexcept{
    ++runtime_check_passed_count;
}
void runtime_check_failed_count_increment(void)noexcept{
    ++runtime_check_failed_count;
}
std::size_t get_runtime_check_count(void)noexcept{
    return runtime_check_count;
}
std::size_t get_runtime_check_passed_count(void)noexcept{
    return runtime_check_passed_count;
}
std::size_t get_runtime_check_failed_count(void)noexcept{
    return runtime_check_failed_count;
}
}//namespace neotest
