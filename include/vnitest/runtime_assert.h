#ifndef VNITEST_RUNTIME_ASSERT_H
#define VNITEST_RUNTIME_ASSERT_H

#include<vnitest/condition_info.h>
#include<vnitest/runtime_assert_stream.hpp>

#define VNITEST_RUNTIME_ASSERT(...) \
    ::vnitest::RuntimeAssertStream( \
        VNITEST_MAKE_CONDITION_INFO((true) == (__VA_ARGS__)) \
    ) \
//
#define VNITEST_RUNTIME_ASSERT_UNARY_OPERATOR(operator__,...) \
    ::vnitest::RuntimeAssertStream( \
        VNITEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR( \
            operator__,__VA_ARGS__ \
        ) \
    ) \
//
#define VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(operator__,lhs__,...) \
    ::vnitest::RuntimeAssertStream( \
        VNITEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
            operator__,lhs__,__VA_ARGS__ \
        ) \
    ) \
//
#define VNITEST_RUNTIME_ASSERT_EQ(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_NE(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_GT(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_GE(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_LT(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_LE(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_AND(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(&&,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_OR(lhs__,...) \
    VNITEST_RUNTIME_ASSERT_BINARY_OPERATOR(||,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_ASSERT_NOT(...) \
    ::vnitest::RuntimeAssertStream( \
        VNITEST_MAKE_CONDITION_INFO((false) == (__VA_ARGS__)) \
    ) \
//

#endif//VNITEST_RUNTIME_ASSERT_H
