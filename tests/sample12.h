#ifndef SAMPLE_12_H
#define SAMPLE_12_H

#include<cstddef>//::std::size_t

#include<iostream>//::std::cout

#include<vnitest/vnitest.h>

#ifdef TEST_SAMPLE_12

VNITEST_CASE("case.counter"){
    static ::std::size_t counter=0;
    VNITEST_RUNTIME_CHECK_LT(counter,3);
    ++counter;
}

VNITEST_CASE("case.counter reg element"){
    static ::std::size_t counter=0;
    VNITEST_RUNTIME_CHECK_LT(counter,3);
    ++counter;
}

VNITEST_GROUP("group.counter"){
    VNITEST_GROUP_ELEMENT_CASE_REPEAT(4,"case.counter");
    VNITEST_GROUP_ELEMENT_CASE_REGEX_REPEAT(4,R"(^case.counter reg.*)");
}

#endif//TEST_SAMPLE_12

void test_sample_12(void)noexcept{
    ::std::cout<<::vnitest::execute_group_to_json("group.counter")<<'\n';
}

#endif//SAMPLE_12_H
