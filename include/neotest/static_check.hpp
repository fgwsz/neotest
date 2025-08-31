#ifndef NEOTEST_STATIC_CHECK_HPP
#define NEOTEST_STATIC_CHECK_HPP

#include"macro.h"
#include"static_string.hpp"

namespace neotest::detail{

template<bool value__>
struct BoolToType{
    constexpr BoolToType(void)noexcept{}
    constexpr BoolToType(BoolToType const&)noexcept{}
};

template<typename StaticString__>
struct StaticCheckHelper{
    constexpr StaticCheckHelper(void)noexcept{}
    [[deprecated("::neotest::static_check(false)")]]
    constexpr bool operator()(::neotest::detail::BoolToType<false>){
        return false;
    }
    constexpr bool operator()(::neotest::detail::BoolToType<true>){
        return true;
    }
};

}//namespace neotest::detail

#define NEOTEST_MAKE_STATIC_CHECK_INFO(...) \
    NEOTEST_MAKE_STATIC_STRING( \
        __FILE__ \
        "(" NEOTEST_TO_STRING(__LINE__) "):" \
        NEOTEST_TO_STRING(__VA_ARGS__) \
    ) \
//

#define NEOTEST_STATIC_CHECK(...) \
    static constexpr bool NEOTEST_UNIQUE_VAR_NAME( \
        neotest_static_check_expr_ \
    )=[](void)noexcept->bool{ \
        ::neotest::detail::StaticCheckHelper< \
            NEOTEST_MAKE_STATIC_CHECK_INFO(__VA_ARGS__) \
        > neotest_static_check={}; \
        ::neotest::detail::BoolToType<static_cast<bool>(__VA_ARGS__)> \
            result={}; \
        return \
            neotest_static_check(result) \
        ; \
    }() \
//

#endif//NEOTEST_STATIC_CHECK_HPP
