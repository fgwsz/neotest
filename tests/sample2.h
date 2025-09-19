#ifndef SAMPLE_2_H
#define SAMPLE_2_H

#include<iostream>//::std::cout
#include<regex>//::std::regex

#include<vnitest/vnitest.h>

#ifdef TEST_SAMPLE_2

VNITEST_CASE("test.Hello"){
    VNITEST_RUNTIME_CHECK_EQ(0,0-3)<<"[msg]: "<<int{1};
    VNITEST_RUNTIME_CHECK_EQ(1,1-3)<<"msg 2";
    VNITEST_RUNTIME_CHECK_EQ(2,2-3)<<"msg 3";
    VNITEST_RUNTIME_ASSERT_EQ(1+2,2)<<"runtime assert failed!";
}
VNITEST_CASE("test.World"){
    VNITEST_RUNTIME_CHECK_EQ(1+1,2);
    VNITEST_RUNTIME_CHECK_EQ(1+2,2);
    VNITEST_RUNTIME_CHECK_EQ(1+4,5);
    VNITEST_SKIP("This is info.")<<"This is msg!";
}
VNITEST_GROUP("test group"){
    VNITEST_GROUP_ELEMENT_CASE("test.Hello");
    VNITEST_GROUP_ELEMENT_CASE("test.World");
    VNITEST_GROUP_ELEMENT_CASE_REGEX(R"(^test\..*)");
    VNITEST_GROUP_ELEMENT_CASE("test.Undefined");
}

#endif//TEST_SAMPLE_2

void test_sample_2(void)noexcept{
    ::std::cout
        <<::vnitest::execute_group_to_json(::std::regex("^test .*"))
        <<'\n';
    ::std::cout
        <<::vnitest::execute_case_to_json({
            "test.Hello"
            ,"test.World"
            ,::std::regex(R"(^test\..*)")
            ,"test.Undefined"
        })
        <<'\n';
}

#endif//SAMPLE_2_H
