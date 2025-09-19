#ifndef SAMPLE_2_H
#define SAMPLE_2_H

#include<iostream>//::std::cout
#include<regex>//::std::regex

#include<neotest/neotest.h>

#ifdef TEST_SAMPLE_2

NEOTEST_CASE("test.Hello"){
    NEOTEST_RUNTIME_CHECK_EQ(0,0-3)<<"[msg]: "<<int{1};
    NEOTEST_RUNTIME_CHECK_EQ(1,1-3)<<"msg 2";
    NEOTEST_RUNTIME_CHECK_EQ(2,2-3)<<"msg 3";
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2)<<"runtime assert failed!";
}
NEOTEST_CASE("test.World"){
    NEOTEST_RUNTIME_CHECK_EQ(1+1,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+2,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+4,5);
    NEOTEST_SKIP("This is info.")<<"This is msg!";
}
NEOTEST_GROUP("test group"){
    NEOTEST_GROUP_ELEMENT_CASE("test.Hello");
    NEOTEST_GROUP_ELEMENT_CASE("test.World");
    NEOTEST_GROUP_ELEMENT_CASE_REGEX(R"(^test\..*)");
    NEOTEST_GROUP_ELEMENT_CASE("test.Undefined");
}

#endif//TEST_SAMPLE_2

void test_sample_2(void)noexcept{
    ::std::cout
        <<::neotest::execute_group_to_json(::std::regex("^test .*"))
        <<'\n';
    ::std::cout
        <<::neotest::execute_case_to_json({
            "test.Hello"
            ,"test.World"
            ,::std::regex(R"(^test\..*)")
            ,"test.Undefined"
        })
        <<'\n';
}

#endif//SAMPLE_2_H
