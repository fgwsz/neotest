#ifndef SAMPLE_7_H
#define SAMPLE_7_H

#include<iostream>//::std::cout
#include<string_view>//::std::string_view
#include<format>//::std::format

#include<vnitest/vnitest.h>

#ifdef TEST_SAMPLE_7

struct Person{
    ::std::string_view name;
    short age;
};
bool operator!=(Person const& p1,Person const& p2)noexcept{
    return (p1.name!=p2.name)
        ||(p1.age!=p2.age);
}
bool operator==(Person const& p1,Person const& p2)noexcept{
    return !(p1!=p2);
}
::vnitest::OStringStream&
operator<<(::vnitest::OStringStream& oss,Person const& p)noexcept{
    return oss<<::std::format("Person{{name:{},age:{}}}",p.name,p.age);
}

VNITEST_CASE("test.PersonCmp.RuntimeCheckPassed"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_CHECK(p1==p3);
    VNITEST_RUNTIME_CHECK(p1!=p2);
    VNITEST_RUNTIME_CHECK_NOT(p1!=p3);
    VNITEST_RUNTIME_CHECK_NOT(p1==p2);
    VNITEST_RUNTIME_CHECK_EQ(p1,p3);
    VNITEST_RUNTIME_CHECK_NE(p1,p2);
}
VNITEST_CASE("test.PersonCmp.RuntimeCheckFailed"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_CHECK(p1!=p3);
    VNITEST_RUNTIME_CHECK(p1==p2);
    VNITEST_RUNTIME_CHECK_NOT(p1==p3);
    VNITEST_RUNTIME_CHECK_NOT(p1!=p2);
    VNITEST_RUNTIME_CHECK_EQ(p1,p2);
    VNITEST_RUNTIME_CHECK_NE(p1,p3);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertPassed"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT(p1==p3);
    VNITEST_RUNTIME_ASSERT(p1!=p2);
    VNITEST_RUNTIME_ASSERT_NOT(p1!=p3);
    VNITEST_RUNTIME_ASSERT_NOT(p1==p2);
    VNITEST_RUNTIME_ASSERT_EQ(p1,p3);
    VNITEST_RUNTIME_ASSERT_NE(p1,p2);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 1"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT(p1!=p3);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 2"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT(p1==p2);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 3"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT_NOT(p1==p3);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 4"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT_NOT(p1!=p2);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 5"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT_EQ(p1,p2);
}
VNITEST_CASE("test.PersonCmp.RuntimeAssertFailed 6"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_RUNTIME_ASSERT_NE(p1,p3);
}
VNITEST_CASE("test.PersonCmp.Skip"){
    Person p1{"Tom",20};
    Person p2{"Jerry",10};
    Person p3{"Tom",20};
    VNITEST_SKIP()<<"p1="<<p1<<",p2="<<p2<<",p3="<<p3;
}
VNITEST_GROUP("test.PersonCmp"){
    VNITEST_GROUP_ELEMENT_CASE_REGEX(R"(^test\.PersonCmp.*)");
}

#endif//TEST_SAMPLE_7

void test_sample_7(void)noexcept{
    ::std::cout<<::vnitest::execute_group_to_json("test.PersonCmp")<<'\n';
}

#endif//SAMPLE_7_H
