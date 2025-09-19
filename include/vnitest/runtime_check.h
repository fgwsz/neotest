#ifndef VNITEST_RUNTIME_CHECK_H
#define VNITEST_RUNTIME_CHECK_H

#include<vnitest/condition_info.h>
#include<vnitest/runtime_check_stream.hpp>

#define VNITEST_RUNTIME_CHECK(...) \
    ::vnitest::RuntimeCheckStream( \
        VNITEST_MAKE_CONDITION_INFO((true) == (__VA_ARGS__)) \
    ) \
//
#define VNITEST_RUNTIME_CHECK_UNARY_OPERATOR(operator__,...) \
    ::vnitest::RuntimeCheckStream( \
        VNITEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR( \
            operator__,__VA_ARGS__ \
        ) \
    ) \
//
#define VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(operator__,lhs__,...) \
    ::vnitest::RuntimeCheckStream( \
        VNITEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
            operator__,lhs__,__VA_ARGS__ \
        ) \
    ) \
//
#define VNITEST_RUNTIME_CHECK_EQ(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(==,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_NE(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_GT(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_GE(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_LT(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_LE(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_AND(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(&&,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_OR(lhs__,...) \
    VNITEST_RUNTIME_CHECK_BINARY_OPERATOR(||,lhs__,__VA_ARGS__) \
//
#define VNITEST_RUNTIME_CHECK_NOT(...) \
    ::vnitest::RuntimeCheckStream( \
        VNITEST_MAKE_CONDITION_INFO((false) == (__VA_ARGS__)) \
    ) \
//

#endif//VNITEST_RUNTIME_CHECK_H
