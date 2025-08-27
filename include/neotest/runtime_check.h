#ifndef NEOTEST_RUNTIME_CHECK_H
#define NEOTEST_RUNTIME_CHECK_H

#include<cstddef>//std::size_t

#include"condition_info.h"

namespace neotest{

void runtime_check(neotest::ConditionInfo const& ci)noexcept;

}//namespace neotest

#define NEOTEST_RUNTIME_CHECK(...) \
    neotest::runtime_check(NEOTEST_MAKE_CONDITION_INFO(__VA_ARGS__)) \
//
#define NEOTEST_RUNTIME_CHECK_UNARY_OPERATOR(operator__,...) \
    neotest::runtime_check( \
        NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,__VA_ARGS__) \
    ) \
//
#define NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(operator__,lhs__,...) \
    neotest::runtime_check( \
        NEOTEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
            operator__,lhs__,__VA_ARGS__ \
        ) \
    ) \
//
#define NEOTEST_RUNTIME_CHECK_EQ(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(==,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_NE(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(!=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_GT(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_GE(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(>=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_LT(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_LE(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(<=,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_AND(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(&&,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_OR(lhs__,...) \
    NEOTEST_RUNTIME_CHECK_BINARY_OPERATOR(||,lhs__,__VA_ARGS__) \
//
#define NEOTEST_RUNTIME_CHECK_NOT(...) \
    NEOTEST_RUNTIME_CHECK_UNARY_OPERATOR(!,(__VA_ARGS__)) \
//

#endif//NEOTEST_RUNTIME_CHECK_H
