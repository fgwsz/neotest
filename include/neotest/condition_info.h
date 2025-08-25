#ifndef NEOTEST_CONDITION_INFO_H
#define NEOTEST_CONDITION_INFO_H

#include"macro.h"
#include"source_info.h"

namespace neotest{

struct ConditionInfo
    :public SourceInfo{
    bool condition;
};

}//namespace neotest

#define NEOTEST_MAKE_CONDITION_INFO(...) \
    neotest::ConditionInfo{ \
        __FILE__ \
        ,__LINE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,NEOTEST_TO_STRING(__VA_ARGS__) \
        ,static_cast<bool>(__VA_ARGS__)
    } \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,rhs__) \
    neotest::ConditionInfo{ \
        __FILE__ \
        ,__LINE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,NEOTEST_TO_STRING(NEOTEST_TO_STRING(operator__)" "NEOTEST_TO_STRING((rhs__)) \
        ,static_cast<bool>(operator__(rhs__))
    } \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR(operator__,lhs__,rhs__) \
    neotest::ConditionInfo{ \
        __FILE__ \
        ,__LINE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,NEOTEST_TO_STRING((lhs__))" "NEOTEST_TO_STRING(operator__)" "NEOTEST_TO_STRING((rhs__)) \
        ,static_cast<bool>((lhs__)operator__(rhs__))
    } \
//

#endif//NEOTEST_CONDITION_INFO_H
