#ifndef VNITEST_CONDITION_INFO_H
#define VNITEST_CONDITION_INFO_H

#include<string_view>//::std::string_view
#include<string>//::std::string
#include<ios>//std::boolalpha

#include<vnitest/macro.h>
#include<vnitest/ostring_stream.hpp>

namespace vnitest{

struct ConditionInfo{
    ::std::string_view file,line;
    ::std::string info;
    bool condition;
};

}//namespace vnitest

#define VNITEST_MAKE_CONDITION_INFO(...) \
    ::vnitest::ConditionInfo{ \
        __FILE__ \
        ,VNITEST_TO_STRING(__LINE__) \
        ,VNITEST_TO_STRING(__VA_ARGS__) \
        ,static_cast<bool>(__VA_ARGS__) \
    } \
//
#define VNITEST_MAKE_CONDITION_INFO_BY_UNARY_OPERATOR(operator__,...) \
    [&](void)->::vnitest::ConditionInfo{ \
        auto const& rhs_ref=(__VA_ARGS__); \
        ::vnitest::OStringStream oss={}; \
        return ::vnitest::ConditionInfo{ \
            __FILE__ \
            ,VNITEST_TO_STRING(__LINE__) \
            ,( \
                oss \
                    <<VNITEST_TO_STRING(operator__) " " \
                    <<"("<<rhs_ref<<")" \
            ).str() \
            ,static_cast<bool>(operator__ rhs_ref) \
        }; \
    }() \
//
#define VNITEST_MAKE_CONDITION_INFO_BY_BINARY_OPERATOR( \
    operator__,lhs__,... \
) \
    [&](void)->::vnitest::ConditionInfo{ \
        auto const& lhs_ref=(lhs__); \
        auto const& rhs_ref=(__VA_ARGS__); \
        ::vnitest::OStringStream oss={}; \
        return ::vnitest::ConditionInfo{ \
            __FILE__ \
            ,VNITEST_TO_STRING(__LINE__) \
            ,( \
                oss \
                    <<"("<<lhs_ref<<")" \
                    <<" " VNITEST_TO_STRING(operator__) " " \
                    <<"("<<rhs_ref<<")" \
            ).str() \
            ,static_cast<bool>(lhs_ref operator__ rhs_ref) \
        }; \
    }() \
//

#endif//VNITEST_CONDITION_INFO_H
