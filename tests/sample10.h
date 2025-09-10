#ifndef SAMPLE_10_H
#define SAMPLE_10_H

#include"neotest/neotest.h"

void my_test_func_1(void)noexcept{
    NEOTEST_RUNTIME_CHECK(1+1==2);
    NEOTEST_RUNTIME_CHECK(1+1!=2)<<"this is msg";
}
void my_test_func_2(void)noexcept{
    NEOTEST_RUNTIME_ASSERT(1+1==2);
    NEOTEST_RUNTIME_ASSERT(1+1!=2)<<"this is msg";
}
void test_sample_10(void)noexcept{
    ::my_test_func_1();
    ::my_test_func_2();
}

#endif//SAMPLE_10_H
