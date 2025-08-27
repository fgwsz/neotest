#ifndef NEOTEST_RUNTIME_ASSERT_H
#define NEOTEST_RUNTIME_ASSERT_H

#include<cstddef>//std::size_t

#include"condition_info.h"

namespace neotest{

void runtime_assert(neotest::ConditionInfo const& ci);

}//namespace neotest

#define NEOTEST_RUNTIME_ASSERT(...) \
    neotest::runtime_assert(NEOTEST_MAKE_CONDITION_INFO(__VA_ARGS__)) \
//
#define NEOTEST_RUNTIME_ASSERT_UNARY_OPERATOR(operator__,...) \
    neotest::runtime_assert( \
        NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,__VA_ARGS__) \
    ) \
//
#define NEOTEST_RUNTIME_ASSERT_BINARY_OPERATOR(operator__,lhs__,...) \
    neotest::runtime_assert( \
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
    NEOTEST_RUNTIME_ASSERT_UNARY_OPERATOR(!,__VA_ARGS__) \
//

#endif//NEOTEST_RUNTIME_ASSERT_H
