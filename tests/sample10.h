#ifndef SAMPLE_10_H
#define SAMPLE_10_H

#include<iostream>//::std::cout

#include"neotest/neotest.h"

void my_test_func_1(void)noexcept{
    NEOTEST_RUNTIME_CHECK(1+1==2);
    NEOTEST_RUNTIME_CHECK(1+1!=2)<<"this is msg";
}
void my_test_func_2(void){
    NEOTEST_RUNTIME_ASSERT(1+1==2);
    NEOTEST_RUNTIME_ASSERT(1+1!=2)<<"this is msg";
}
void test_sample_10(void)noexcept{
    ::my_test_func_1();
    try{
        ::my_test_func_2();
    }catch(::neotest::RuntimeAssertFailedException const& e){
        ::std::cout<<e.what()<<'\n';
    }
}

#endif//SAMPLE_10_H
