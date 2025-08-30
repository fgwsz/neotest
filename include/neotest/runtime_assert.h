#ifndef NEOTEST_RUNTIME_ASSERT_H
#define NEOTEST_RUNTIME_ASSERT_H

#include"condition_info.h"
#include"runtime_assert_stream.hpp"

#define NEOTEST_RUNTIME_ASSERT(...) \
    ::neotest::RuntimeAssertStream( \
        NEOTEST_MAKE_CONDITION_INFO((true) == (__VA_ARGS__)) \
    ) \
//
#define NEOTEST_RUNTIME_ASSERT_UNARY_OPERATOR(operator__,...) \
    ::neotest::RuntimeAssertStream( \
        NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR( \
            operator__,__VA_ARGS__ \
        ) \
    ) \
//
#define NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(operator__,lhs__,...) \
    ::neotest::RuntimeAssertStream( \
        NEOTEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
            operator__,lhs__,__VA_ARGS__ \
        ) \
    ) \
//
#define NEOTEST_RUNTIME_ASSERT_EQ(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(==,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_NE(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(!=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_GT(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_GE(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(>=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_LT(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_LE(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(<=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_AND(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(&&,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_OR(lhs__,...) \
    NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(||,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_ASSERT_NOT(...) \
    ::neotest::RuntimeAssertStream( \
        NEOTEST_MAKE_CONDITION_INFO((false) == (__VA_ARGS__)) \
    ) \
//

#endif//NEOTEST_RUNTIME_ASSERT_H
