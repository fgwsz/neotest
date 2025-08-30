#ifndef NEOTEST_CONDITION_INFO_H
#define NEOTEST_CONDITION_INFO_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<ios>//std::boolalpha
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
        ,static_cast<bool>(__VA_ARGS__) /*求值*/ \
    } \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,...) \
    [&](void)->::neotest::ConditionInfo{ \
        auto const& rhs_ref=(__VA_ARGS__); \
        return ::neotest::ConditionInfo{ \
            __FILE__ \
            ,NEOTEST_TO_STRING(__LINE__) \
            ,( \
                ::std::ostringstream{} \
                    <<::std::boolalpha \
                    <<NEOTEST_TO_STRING(operator__) " " \
                    <<"("<<rhs_ref<<")" \
            ).str() \
            ,static_cast<bool>(operator__ rhs_ref) \
        }; \
    }() \
//
#define NEOTEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
    operator__,lhs__,... \
) \
    [&](void)->::neotest::ConditionInfo{ \
        auto const& lhs_ref=(lhs__); \
        auto const& rhs_ref=(__VA_ARGS__); \
        return ::neotest::ConditionInfo{ \
            __FILE__ \
            ,NEOTEST_TO_STRING(__LINE__) \
            ,( \
                ::std::ostringstream{} \
                    <<::std::boolalpha \
                    <<"("<<lhs_ref<<")" \
                    <<" " NEOTEST_TO_STRING(operator__) " " \
                    <<"("<<rhs_ref<<")" \
            ).str() \
            ,static_cast<bool>(lhs_ref operator__ rhs_ref) \
        }; \
    }() \
//

#endif//NEOTEST_CONDITION_INFO_H
