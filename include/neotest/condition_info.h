#ifndef NEOTEST_CONDITION_INFO_H
#define NEOTEST_CONDITION_INFO_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<sstream>//::std::ostringstream

#include"macro.h"

namespace neotest{

struct ConditionInfo{
    ::std::string_view file,line;
    ::std::string info;
    bool condition;
};

}//namespace neotest

#define NEOTEST_MAKE_CONDITION_INFO(...) \
    ::neotest::ConditionInfo{ \
        __FILE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,NEOTEST_TO_STRING(__VA_ARGS__) \
        ,static_cast<bool>(__VA_ARGS__) \
    } \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,...) \
    ::neotest::ConditionInfo{ \
        __FILE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,( \
            ::std::ostringstream{} \
                <<NEOTEST_TO_STRING(operator__) " " \
                <<(__VA_ARGS__) \
        ).str() \
        ,static_cast<bool>(operator__ (__VA_ARGS__)) \
    } \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
    operator__,lhs__,... \
) \
    ::neotest::ConditionInfo{ \
        __FILE__ \
        ,NEOTEST_TO_STRING(__LINE__) \
        ,( \
            ::std::ostringstream{} \
                <<(lhs__) \
                <<" " NEOTEST_TO_STRING(operator__) " " \
                <<(__VA_ARGS__) \
        ).str() \
        ,static_cast<bool>((lhs__) operator__ (__VA_ARGS__)) \
    } \
//

#endif//NEOTEST_CONDITION_INFO_H
