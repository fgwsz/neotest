#ifndef SAMPLE_8_H
#define SAMPLE_8_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<stdexcept>//::std::runtime_error
#include<ios>//::std::ios
#include<iostream>//::std::cout
#include<fstream>//::std::ofstream

#include"neotest/neotest.h"

#ifdef TEST_SAMPLE_8

NEOTEST_CASE("c_str_exception"){
    throw "c_str exception";
}
NEOTEST_CASE("string_view_exception"){
    throw ::std::string_view{"string view exception"};
}
NEOTEST_CASE("string_exception"){
    throw ::std::string{"string exception"};
}
NEOTEST_CASE("std_exception"){
    throw std::runtime_error{"std::exception"};
}
NEOTEST_CASE("unknown_exception"){
    struct Foo{};
    throw Foo{};
}
NEOTEST_CASE("empty_c_str_exception"){
    throw "";
}
NEOTEST_CASE("empty_string_view_exception"){
    throw std::string_view{""};
}
NEOTEST_CASE("empty_string_exception"){
    throw std::string{""};
}
NEOTEST_CASE("empty_std_exception"){
    throw std::runtime_error{""};
}
NEOTEST_CASE("check_passed"){
    NEOTEST_RUNTIME_CHECK(1==1);
    NEOTEST_RUNTIME_CHECK(2!=1);
    NEOTEST_RUNTIME_CHECK(2>1);
    NEOTEST_RUNTIME_CHECK(2>=1);
    NEOTEST_RUNTIME_CHECK(2>=2);
    NEOTEST_RUNTIME_CHECK(1<2);
    NEOTEST_RUNTIME_CHECK(1<=2);
    NEOTEST_RUNTIME_CHECK(1<=1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(==,1,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,2,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>,2,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,2,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,2,2);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<,1,2);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,1,2);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,1,1);
    NEOTEST_RUNTIME_CHECK_EQ(1,1);
    NEOTEST_RUNTIME_CHECK_NE(2,1);
    NEOTEST_RUNTIME_CHECK_GT(2,1);
    NEOTEST_RUNTIME_CHECK_GE(2,1);
    NEOTEST_RUNTIME_CHECK_GE(2,2);
    NEOTEST_RUNTIME_CHECK_LT(1,2);
    NEOTEST_RUNTIME_CHECK_LE(1,2);
    NEOTEST_RUNTIME_CHECK_LE(1,1);
    NEOTEST_RUNTIME_CHECK_AND(true,true);
    NEOTEST_RUNTIME_CHECK_OR(false,true);
    NEOTEST_RUNTIME_CHECK_NOT(false);
}
NEOTEST_CASE("check_failed"){
    NEOTEST_RUNTIME_CHECK(!(1==1));
    NEOTEST_RUNTIME_CHECK(!(2!=1));
    NEOTEST_RUNTIME_CHECK(!(2>1));
    NEOTEST_RUNTIME_CHECK(!(2>=1));
    NEOTEST_RUNTIME_CHECK(!(2>=2));
    NEOTEST_RUNTIME_CHECK(!(1<2));
    NEOTEST_RUNTIME_CHECK(!(1<=2));
    NEOTEST_RUNTIME_CHECK(!(1<=1));
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(==,2,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,1,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>,2,2);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,1,2);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<,1,1);
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,2,1);
    NEOTEST_RUNTIME_CHECK_EQ(2,1);
    NEOTEST_RUNTIME_CHECK_NE(1,1);
    NEOTEST_RUNTIME_CHECK_GT(2,2);
    NEOTEST_RUNTIME_CHECK_GE(1,2);
    NEOTEST_RUNTIME_CHECK_LT(1,1);
    NEOTEST_RUNTIME_CHECK_LE(2,1);
    NEOTEST_RUNTIME_CHECK_AND(true,false);
    NEOTEST_RUNTIME_CHECK_OR(false,false);
    NEOTEST_RUNTIME_CHECK_NOT(true);
}
NEOTEST_CASE("assert_passed"){
    NEOTEST_RUNTIME_ASSERT(1==1);
    NEOTEST_RUNTIME_ASSERT(2!=1);
    NEOTEST_RUNTIME_ASSERT(2>1);
    NEOTEST_RUNTIME_ASSERT(2>=1);
    NEOTEST_RUNTIME_ASSERT(2>=2);
    NEOTEST_RUNTIME_ASSERT(1<2);
    NEOTEST_RUNTIME_ASSERT(1<=2);
    NEOTEST_RUNTIME_ASSERT(1<=1);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,1,1);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,2,1);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,2,1);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,2,1);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,2,2);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,1,2);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,1,2);
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,1,1);
    NEOTEST_RUNTIME_ASSERT_EQ(1,1);
    NEOTEST_RUNTIME_ASSERT_NE(2,1);
    NEOTEST_RUNTIME_ASSERT_GT(2,1);
    NEOTEST_RUNTIME_ASSERT_GE(2,1);
    NEOTEST_RUNTIME_ASSERT_GE(2,2);
    NEOTEST_RUNTIME_ASSERT_LT(1,2);
    NEOTEST_RUNTIME_ASSERT_LE(1,2);
    NEOTEST_RUNTIME_ASSERT_LE(1,1);
    NEOTEST_RUNTIME_ASSERT_AND(true,true);
    NEOTEST_RUNTIME_ASSERT_OR(false,true);
    NEOTEST_RUNTIME_ASSERT_NOT(false);
}
NEOTEST_CASE("assert_failed_1"){
    NEOTEST_RUNTIME_ASSERT(!(1==1));
}
NEOTEST_CASE("assert_failed_2"){
    NEOTEST_RUNTIME_ASSERT(!(2!=1));
}
NEOTEST_CASE("assert_failed_3"){
    NEOTEST_RUNTIME_ASSERT(!(2>1));
}
NEOTEST_CASE("assert_failed_4"){
    NEOTEST_RUNTIME_ASSERT(!(2>=1));
}
NEOTEST_CASE("assert_failed_5"){
    NEOTEST_RUNTIME_ASSERT(!(2>=2));
}
NEOTEST_CASE("assert_failed_6"){
    NEOTEST_RUNTIME_ASSERT(!(1<2));
}
NEOTEST_CASE("assert_failed_7"){
    NEOTEST_RUNTIME_ASSERT(!(1<=2));
}
NEOTEST_CASE("assert_failed_8"){
    NEOTEST_RUNTIME_ASSERT(!(1<=1));
}
NEOTEST_CASE("assert_failed_9"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,2,1);
}
NEOTEST_CASE("assert_failed_10"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,1,1);
}
NEOTEST_CASE("assert_failed_11"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,2,2);
}
NEOTEST_CASE("assert_failed_12"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,1,2);
}
NEOTEST_CASE("assert_failed_13"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,1,1);
}
NEOTEST_CASE("assert_failed_14"){
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,2,1);
}
NEOTEST_CASE("assert_failed_15"){
    NEOTEST_RUNTIME_ASSERT_EQ(2,1);
}
NEOTEST_CASE("assert_failed_16"){
    NEOTEST_RUNTIME_ASSERT_NE(1,1);
}
NEOTEST_CASE("assert_failed_17"){
    NEOTEST_RUNTIME_ASSERT_GT(2,2);
}
NEOTEST_CASE("assert_failed_18"){
    NEOTEST_RUNTIME_ASSERT_GE(1,2);
}
NEOTEST_CASE("assert_failed_19"){
    NEOTEST_RUNTIME_ASSERT_LT(1,1);
}
NEOTEST_CASE("assert_failed_20"){
    NEOTEST_RUNTIME_ASSERT_LE(2,1);
}
NEOTEST_CASE("assert_failed_21"){
    NEOTEST_RUNTIME_ASSERT_AND(true,false);
}
NEOTEST_CASE("assert_failed_22"){
    NEOTEST_RUNTIME_ASSERT_OR(false,false);
}
NEOTEST_CASE("assert_failed_23"){
    NEOTEST_RUNTIME_ASSERT_NOT(true);
}
NEOTEST_GROUP("passed_group"){
    NEOTEST_GROUP_ELEMENT_CASE("check_passed");
    NEOTEST_GROUP_ELEMENT_CASE("assert_passed");
}
NEOTEST_GROUP("failed_group"){
    NEOTEST_GROUP_ELEMENT_CASE("c_str_exception");
    NEOTEST_GROUP_ELEMENT_CASE("string_exception");
    NEOTEST_GROUP_ELEMENT_CASE("std_exception");
    NEOTEST_GROUP_ELEMENT_CASE("unknown_exception");
    NEOTEST_GROUP_ELEMENT_CASE("empty_c_str_exception");
    NEOTEST_GROUP_ELEMENT_CASE("empty_string_exception");
    NEOTEST_GROUP_ELEMENT_CASE("empty_std_exception");
    NEOTEST_GROUP_ELEMENT_CASE("check_failed");
    NEOTEST_GROUP_ELEMENT_CASE_REGEX(R"(^assert_failed_.*)");
    NEOTEST_GROUP_ELEMENT_CASE("undefined");
}


#endif//TEST_SAMPLE_8

void test_console_output(void)noexcept{
    ::std::cout<<::neotest::execute_case_all_to_json()<<'\n';
    ::std::cout<<::neotest::execute_group_all_to_json()<<'\n';
}
void test_file_output(void)noexcept{
    ::std::ofstream ofs("sample1.txt",::std::ios::out|::std::ios::trunc);
    if(ofs.is_open()){
        auto line=::std::string(50,'=');
        //ofs<<::neotest::execute_case_all_to_json()<<'\n';
        ofs<<::std::format("execute group all() {}\n",line);
        ofs<<::neotest::execute_group_all_to_json()<<'\n';
        ofs<<::std::format("execute group(group) {}\n",line);
        ofs<<::neotest::execute_group_to_json("passed_group")<<'\n';
        ofs<<::neotest::execute_group_to_json("failed_group")<<'\n';
        ofs<<::std::format("execute group(group list) {}\n",line);
        ofs<<::neotest::execute_group_to_json({"passed_group","failed_group"})<<'\n';
        ofs.close();
    }else{
        std::cout<<"Unable to open file for writing."<<'\n';
    }
}
void test_sample_8(void)noexcept{
    ::test_file_output();
}

#endif//SAMPLE_8_H
