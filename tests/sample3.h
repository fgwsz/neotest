#ifndef SAMPLE_3_H
#define SAMPLE_3_H

#include<iostream>//::std::cout

#include"neotest/neotest.h"

#ifdef TEST_SAMPLE_3

NEOTEST_CASE("test.StringCmp.RuntimeCheckPassed"){

    using string_t=::std::string;

    NEOTEST_RUNTIME_CHECK(string_t{"hello"}==string_t{"hello"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}!=string_t{"world"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}>string_t{"hell"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}>=string_t{"hell"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}<string_t{"hello!"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}<=string_t{"hello!"});

    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}==string_t{"hello"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}!=string_t{"world"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}>string_t{"hell"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}>=string_t{"hell"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}<string_t{"hello!"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}<=string_t{"hello!"}));

    NEOTEST_RUNTIME_CHECK_EQ(string_t{"hello"},string_t{"hello"});
    NEOTEST_RUNTIME_CHECK_NE(string_t{"hello"},string_t{"world"});
    NEOTEST_RUNTIME_CHECK_GT(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_CHECK_GE(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_CHECK_LT(string_t{"hello"},string_t{"hello!"});
    NEOTEST_RUNTIME_CHECK_LE(string_t{"hello"},string_t{"hello!"});
}

NEOTEST_CASE("test.StringCmp.RuntimeCheckFailed"){

    using string_t=::std::string;

    NEOTEST_RUNTIME_CHECK(string_t{"hello"}!=string_t{"hello"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}==string_t{"world"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}<=string_t{"hell"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}<string_t{"hell"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}>=string_t{"hello!"});
    NEOTEST_RUNTIME_CHECK(string_t{"hello"}>string_t{"hello!"});

    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}!=string_t{"hello"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}==string_t{"world"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}<=string_t{"hell"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}<string_t{"hell"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}>=string_t{"hello!"}));
    NEOTEST_RUNTIME_CHECK_NOT(!(string_t{"hello"}>string_t{"hello!"}));

    NEOTEST_RUNTIME_CHECK_NE(string_t{"hello"},string_t{"hello"});
    NEOTEST_RUNTIME_CHECK_EQ(string_t{"hello"},string_t{"world"});
    NEOTEST_RUNTIME_CHECK_LE(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_CHECK_LT(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_CHECK_GE(string_t{"hello"},string_t{"hello!"});
    NEOTEST_RUNTIME_CHECK_GT(string_t{"hello"},string_t{"hello!"});
}

NEOTEST_CASE("test.StringCmp.RuntimeAssertPassed"){

    using string_t=::std::string;

    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}==string_t{"hello"});
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}!=string_t{"world"});
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}>string_t{"hell"});
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}>=string_t{"hell"});
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}<string_t{"hello!"});
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}<=string_t{"hello!"});

    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}==string_t{"hello"}));
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}!=string_t{"world"}));
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}>string_t{"hell"}));
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}>=string_t{"hell"}));
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}<string_t{"hello!"}));
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}<=string_t{"hello!"}));

    NEOTEST_RUNTIME_ASSERT_EQ(string_t{"hello"},string_t{"hello"});
    NEOTEST_RUNTIME_ASSERT_NE(string_t{"hello"},string_t{"world"});
    NEOTEST_RUNTIME_ASSERT_GT(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_ASSERT_GE(string_t{"hello"},string_t{"hell"});
    NEOTEST_RUNTIME_ASSERT_LT(string_t{"hello"},string_t{"hello!"});
    NEOTEST_RUNTIME_ASSERT_LE(string_t{"hello"},string_t{"hello!"});
}

NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 1"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}!=string_t{"hello"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 2"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}==string_t{"world"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 3"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}<=string_t{"hell"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 4"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}<string_t{"hell"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 5"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}>=string_t{"hello!"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 6"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT(string_t{"hello"}>string_t{"hello!"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 7"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}!=string_t{"hello"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 8"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}==string_t{"world"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 9"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}<=string_t{"hell"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 10"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}<string_t{"hell"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 11"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}>=string_t{"hello!"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 12"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NOT(!(string_t{"hello"}>string_t{"hello!"}));
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 13"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_NE(string_t{"hello"},string_t{"hello"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 14"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_EQ(string_t{"hello"},string_t{"world"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 15"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_LE(string_t{"hello"},string_t{"hell"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 16"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_LT(string_t{"hello"},string_t{"hell"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 17"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_GE(string_t{"hello"},string_t{"hello!"});
}
NEOTEST_CASE("test.StringCmp.RuntimeAssertFailed 18"){
    using string_t=::std::string;
    NEOTEST_RUNTIME_ASSERT_GT(string_t{"hello"},string_t{"hello!"});
}

NEOTEST_GROUP("test.StringCmp"){
    NEOTEST_GROUP_ELEMENT_CASE("test.StringCmp.RuntimeCheckPassed");
    NEOTEST_GROUP_ELEMENT_CASE("test.StringCmp.RuntimeCheckFailed");
    NEOTEST_GROUP_ELEMENT_CASE("test.StringCmp.RuntimeAssertPassed");
    NEOTEST_GROUP_ELEMENT_CASE_REGEX(
        R"(^test\.StringCmp\.RuntimeAssertFailed .*)"
    );
}

#endif//TEST_SAMPLE_3

void test_sample_3(void)noexcept{
    ::std::cout
        <<::neotest::execute_group_to_json("test.StringCmp")
        <<'\n';
}

#endif//SAMPLE_3_H
