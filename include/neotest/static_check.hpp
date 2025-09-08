#ifndef NEOTEST_STATIC_CHECK_HPP
#define NEOTEST_STATIC_CHECK_HPP

#include<cstddef>//::std::size_t

#include<type_traits>//::std::is_same_v

#include"macro.h"
#include"static_string.hpp"

namespace neotest::detail{

template<bool value__>
struct Bool{
    constexpr Bool(void)noexcept{}
    constexpr Bool(Bool const&)noexcept{}
};

template<typename File__,typename Line__,typename Info__>
struct StaticCheck{
    constexpr StaticCheck(void)noexcept{}
    constexpr StaticCheck(StaticCheck const&)noexcept{}
    [[deprecated("::neotest::static_check(false)")]]
    constexpr bool operator()(::neotest::detail::Bool<false>)const noexcept{
        return false;
    }
    constexpr bool operator()(::neotest::detail::Bool<true>)const noexcept{
        return true;
    }
};

template<typename File__>
struct File{};

template<::std::size_t line__>
struct Line{};

template<typename File__>
struct Info{};

template<auto lhs__,auto rhs__>
struct ValueEqual{};

template<auto lhs__,auto rhs__>
struct ValueNotEqual{};

template<auto lhs__,auto rhs__>
struct ValueGreaterThan{};

template<auto lhs__,auto rhs__>
struct ValueGreaterEqual{};

template<auto lhs__,auto rhs__>
struct ValueLessThan{};

template<auto lhs__,auto rhs__>
struct ValueLessEqual{};

template<bool lhs__,bool rhs__>
struct ValueAnd{};

template<bool lhs__,bool rhs__>
struct ValueOr{};

template<typename LHS__,typename RHS__>
struct TypeEqual{};

template<typename LHS__,typename RHS__>
struct TypeNotEqual{};

}//namespace neotest::detail

#define NEOTEST_STATIC_CHECK(...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::Info<NEOTEST_MAKE_STATIC_STRING( \
                "(true) == (" NEOTEST_TO_STRING(__VA_ARGS__) ")" \
            )> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>(__VA_ARGS__)> \
            result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_NOT(...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::Info<NEOTEST_MAKE_STATIC_STRING( \
                "(false) == (" NEOTEST_TO_STRING(__VA_ARGS__) ")" \
            )> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<!(static_cast<bool>(__VA_ARGS__))> \
            result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_EQ(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueEqual<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) == (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_NE(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueNotEqual<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) != (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_GT(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueGreaterThan<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) > (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_GE(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueGreaterEqual<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) >= (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_LT(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueLessThan<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) < (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_LE(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr auto lhs=lhs__; \
        constexpr auto rhs=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueLessEqual<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) <= (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_AND(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr bool lhs=static_cast<bool>(lhs__); \
        constexpr bool rhs=static_cast<bool>(__VA_ARGS__); \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueAnd<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) && (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_VALUE_OR(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        constexpr bool lhs=static_cast<bool>(lhs__); \
        constexpr bool rhs=static_cast<bool>(__VA_ARGS__); \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::ValueOr<lhs,rhs> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            (lhs) || (rhs) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_TYPE_EQ(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        using lhs_t=lhs__; \
        using rhs_t=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::TypeEqual<lhs_t,rhs_t> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            ::std::is_same_v<lhs_t,rhs_t> \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#define NEOTEST_STATIC_CHECK_TYPE_NE(lhs__,...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        using lhs_t=lhs__; \
        using rhs_t=__VA_ARGS__; \
        constexpr ::neotest::detail::StaticCheck< \
            ::neotest::detail::File<NEOTEST_MAKE_STATIC_STRING(__FILE__)> \
            ,::neotest::detail::Line<__LINE__> \
            ,::neotest::detail::TypeNotEqual<lhs_t,rhs_t> \
        > static_check={}; \
        constexpr ::neotest::detail::Bool<static_cast<bool>( \
            !(::std::is_same_v<lhs_t,rhs_t>) \
        )> result={}; \
        return \
            static_check(result) \
        ; \
    }() \
//

#endif//NEOTEST_STATIC_CHECK_HPP
