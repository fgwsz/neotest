#ifndef SAMPLE_1_H
#define SAMPLE_1_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<stdexcept>//::std::runtime_error
#include<ios>//::std::ios
#include<iostream>//::std::cout
#include<fstream>//::std::ofstream

#include<vnitest/vnitest.h>

#ifdef TEST_SAMPLE_1

VNITEST_CASE("c_str_exception"){
    throw "c_str exception";
}
VNITEST_CASE("string_view_exception"){
    throw ::std::string_view{"string view exception"};
}
VNITEST_CASE("string_exception"){
    throw ::std::string{"string exception"};
}
VNITEST_CASE("std_exception"){
    throw std::runtime_error{"std::exception"};
}
VNITEST_CASE("unknown_exception"){
    struct Foo{};
    throw Foo{};
}
VNITEST_CASE("empty_c_str_exception"){
    throw "";
}
VNITEST_CASE("empty_string_view_exception"){
    throw std::string_view{""};
}
VNITEST_CASE("empty_string_exception"){
    throw std::string{""};
}
VNITEST_CASE("empty_std_exception"){
    throw std::runtime_error{""};
}
VNITEST_CASE("check_passed"){
    VNITEST_RUNTIME_CHECK(1==1);
    VNITEST_RUNTIME_CHECK(2!=1);
    VNITEST_RUNTIME_CHECK(2>1);
    VNITEST_RUNTIME_CHECK(2>=1);
    VNITEST_RUNTIME_CHECK(2>=2);
    VNITEST_RUNTIME_CHECK(1<2);
    VNITEST_RUNTIME_CHECK(1<=2);
    VNITEST_RUNTIME_CHECK(1<=1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(==,1,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,2,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>,2,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,2,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,2,2);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<,1,2);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,1,2);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,1,1);
    VNITEST_RUNTIME_CHECK_EQ(1,1);
    VNITEST_RUNTIME_CHECK_NE(2,1);
    VNITEST_RUNTIME_CHECK_GT(2,1);
    VNITEST_RUNTIME_CHECK_GE(2,1);
    VNITEST_RUNTIME_CHECK_GE(2,2);
    VNITEST_RUNTIME_CHECK_LT(1,2);
    VNITEST_RUNTIME_CHECK_LE(1,2);
    VNITEST_RUNTIME_CHECK_LE(1,1);
    VNITEST_RUNTIME_CHECK_AND(true,true);
    VNITEST_RUNTIME_CHECK_OR(false,true);
    VNITEST_RUNTIME_CHECK_NOT(false);
}
VNITEST_CASE("check_failed"){
    VNITEST_RUNTIME_CHECK(!(1==1));
    VNITEST_RUNTIME_CHECK(!(2!=1));
    VNITEST_RUNTIME_CHECK(!(2>1));
    VNITEST_RUNTIME_CHECK(!(2>=1));
    VNITEST_RUNTIME_CHECK(!(2>=2));
    VNITEST_RUNTIME_CHECK(!(1<2));
    VNITEST_RUNTIME_CHECK(!(1<=2));
    VNITEST_RUNTIME_CHECK(!(1<=1));
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(==,2,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,1,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>,2,2);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,1,2);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<,1,1);
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,2,1);
    VNITEST_RUNTIME_CHECK_EQ(2,1);
    VNITEST_RUNTIME_CHECK_NE(1,1);
    VNITEST_RUNTIME_CHECK_GT(2,2);
    VNITEST_RUNTIME_CHECK_GE(1,2);
    VNITEST_RUNTIME_CHECK_LT(1,1);
    VNITEST_RUNTIME_CHECK_LE(2,1);
    VNITEST_RUNTIME_CHECK_AND(true,false);
    VNITEST_RUNTIME_CHECK_OR(false,false);
    VNITEST_RUNTIME_CHECK_NOT(true);
}
VNITEST_CASE("assert_passed"){
    VNITEST_RUNTIME_ASSERT(1==1);
    VNITEST_RUNTIME_ASSERT(2!=1);
    VNITEST_RUNTIME_ASSERT(2>1);
    VNITEST_RUNTIME_ASSERT(2>=1);
    VNITEST_RUNTIME_ASSERT(2>=2);
    VNITEST_RUNTIME_ASSERT(1<2);
    VNITEST_RUNTIME_ASSERT(1<=2);
    VNITEST_RUNTIME_ASSERT(1<=1);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,1,1);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,2,1);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,2,1);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,2,1);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,2,2);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,1,2);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,1,2);
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,1,1);
    VNITEST_RUNTIME_ASSERT_EQ(1,1);
    VNITEST_RUNTIME_ASSERT_NE(2,1);
    VNITEST_RUNTIME_ASSERT_GT(2,1);
    VNITEST_RUNTIME_ASSERT_GE(2,1);
    VNITEST_RUNTIME_ASSERT_GE(2,2);
    VNITEST_RUNTIME_ASSERT_LT(1,2);
    VNITEST_RUNTIME_ASSERT_LE(1,2);
    VNITEST_RUNTIME_ASSERT_LE(1,1);
    VNITEST_RUNTIME_ASSERT_AND(true,true);
    VNITEST_RUNTIME_ASSERT_OR(false,true);
    VNITEST_RUNTIME_ASSERT_NOT(false);
}
VNITEST_CASE("assert_failed_1"){
    VNITEST_RUNTIME_ASSERT(!(1==1));
}
VNITEST_CASE("assert_failed_2"){
    VNITEST_RUNTIME_ASSERT(!(2!=1));
}
VNITEST_CASE("assert_failed_3"){
    VNITEST_RUNTIME_ASSERT(!(2>1));
}
VNITEST_CASE("assert_failed_4"){
    VNITEST_RUNTIME_ASSERT(!(2>=1));
}
VNITEST_CASE("assert_failed_5"){
    VNITEST_RUNTIME_ASSERT(!(2>=2));
}
VNITEST_CASE("assert_failed_6"){
    VNITEST_RUNTIME_ASSERT(!(1<2));
}
VNITEST_CASE("assert_failed_7"){
    VNITEST_RUNTIME_ASSERT(!(1<=2));
}
VNITEST_CASE("assert_failed_8"){
    VNITEST_RUNTIME_ASSERT(!(1<=1));
}
VNITEST_CASE("assert_failed_9"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,2,1);
}
VNITEST_CASE("assert_failed_10"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,1,1);
}
VNITEST_CASE("assert_failed_11"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,2,2);
}
VNITEST_CASE("assert_failed_12"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,1,2);
}
VNITEST_CASE("assert_failed_13"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,1,1);
}
VNITEST_CASE("assert_failed_14"){
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,2,1);
}
VNITEST_CASE("assert_failed_15"){
    VNITEST_RUNTIME_ASSERT_EQ(2,1);
}
VNITEST_CASE("assert_failed_16"){
    VNITEST_RUNTIME_ASSERT_NE(1,1);
}
VNITEST_CASE("assert_failed_17"){
    VNITEST_RUNTIME_ASSERT_GT(2,2);
}
VNITEST_CASE("assert_failed_18"){
    VNITEST_RUNTIME_ASSERT_GE(1,2);
}
VNITEST_CASE("assert_failed_19"){
    VNITEST_RUNTIME_ASSERT_LT(1,1);
}
VNITEST_CASE("assert_failed_20"){
    VNITEST_RUNTIME_ASSERT_LE(2,1);
}
VNITEST_CASE("assert_failed_21"){
    VNITEST_RUNTIME_ASSERT_AND(true,false);
}
VNITEST_CASE("assert_failed_22"){
    VNITEST_RUNTIME_ASSERT_OR(false,false);
}
VNITEST_CASE("assert_failed_23"){
    VNITEST_RUNTIME_ASSERT_NOT(true);
}
VNITEST_GROUP("passed_group"){
    VNITEST_GROUP_ELEMENT_CASE("check_passed");
    VNITEST_GROUP_ELEMENT_CASE("assert_passed");
}
VNITEST_GROUP("failed_group"){
    VNITEST_GROUP_ELEMENT_CASE("c_str_exception");
    VNITEST_GROUP_ELEMENT_CASE("string_exception");
    VNITEST_GROUP_ELEMENT_CASE("std_exception");
    VNITEST_GROUP_ELEMENT_CASE("unknown_exception");
    VNITEST_GROUP_ELEMENT_CASE("empty_c_str_exception");
    VNITEST_GROUP_ELEMENT_CASE("empty_string_exception");
    VNITEST_GROUP_ELEMENT_CASE("empty_std_exception");
    VNITEST_GROUP_ELEMENT_CASE("check_failed");
    VNITEST_GROUP_ELEMENT_CASE_REGEX(R"(^assert_failed_.*)");
    VNITEST_GROUP_ELEMENT_CASE("undefined");
}

#endif//TEST_SAMPLE_1

void test_file_output(void)noexcept{
    ::std::ofstream ofs("sample1.txt",::std::ios::out|::std::ios::trunc);
    if(ofs.is_open()){
        ofs<<::vnitest::execute_group_to_json({
                "passed_group",
                "failed_group"
        })<<'\n';
        ofs.close();
    }else{
        std::cout<<"Unable to open file for writing."<<'\n';
    }
}
void test_sample_1(void)noexcept{
    ::test_file_output();
}

#endif//SAMPLE_1_H
