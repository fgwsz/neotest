#ifndef TEST_SAMPLE_H
#define TEST_SAMPLE_H

#include<iostream>//::std::cout
#include<string>//::std::string
#include<format>//std::format

//#define TEST_SAMPLE_8

#ifndef TEST_SAMPLE_8
#   define TEST_SAMPLE_1
#   include"sample1.h"
#   define TEST_SAMPLE_2
#   include"sample2.h"
#   define TEST_SAMPLE_3
#   include"sample3.h"
#   define TEST_SAMPLE_4
#   include"sample4.h"
#   define TEST_SAMPLE_5
#   include "sample5.h"
#   define TEST_SAMPLE_6
#   include "sample6.h"
#   define TEST_SAMPLE_7
#   include "sample7.h"
#else
#   include "sample8.h"
#endif


void test_sample(void)noexcept{
    static auto const line=::std::string(40,'=');
    auto execute_sample=[&](auto const& info,auto const& func){
        ::std::cout<<::std::format("{} {} Begin {}\n",line,info,line);
        func();
        ::std::cout<<::std::format("{} {} End   {}\n",line,info,line);
    };
#ifndef TEST_SAMPLE_8
    execute_sample("Sample 1",::test_sample_1);
    execute_sample("Sample 2",::test_sample_2);
    execute_sample("Sample 3",::test_sample_3);
    execute_sample("Sample 4",::test_sample_4);
    execute_sample("Sample 7",::test_sample_7);
#else
    execute_sample("Sample 8",::test_sample_8);
#endif
}

#endif//TEST_SAMPLE_H
