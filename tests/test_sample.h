#ifndef TEST_SAMPLE_H
#define TEST_SAMPLE_H

#include<iostream>//::std::cout ::std::endl
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
#   define TEST_SAMPLE_12
#   include "sample12.h"
#else
#   include "sample8.h"
#endif
#include"sample9.h"
#include"sample10.h"
#include"sample11.h"

void test_sample(void)noexcept{
    static auto const line=::std::string(30,'=');
    auto execute_sample=[&](auto const& info,auto const& func){
        ::std::cout<<::std::format("{}[ Sample {} Begin ]{}",line,info,line)
            <<::std::endl;
        func();
        ::std::cout<<::std::format("{}[ Sample {} End   ]{}",line,info,line)
            <<::std::endl;
    };
#define EXECUTE_SAMPLE(id__) \
    execute_sample(#id__,::test_sample_##id__) \
//
#ifndef TEST_SAMPLE_8
    EXECUTE_SAMPLE(1);
    EXECUTE_SAMPLE(2);
    EXECUTE_SAMPLE(3);
    EXECUTE_SAMPLE(4);
    EXECUTE_SAMPLE(7);
#else
    EXECUTE_SAMPLE(8);
#endif
    EXECUTE_SAMPLE(9);
    EXECUTE_SAMPLE(10);
    EXECUTE_SAMPLE(11);
#ifndef TEST_SAMPLE_8
    EXECUTE_SAMPLE(12);
#endif
    //...
#undef EXECUTE_SAMPLE
}

#endif//TEST_SAMPLE_H
