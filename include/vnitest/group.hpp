#ifndef VNITEST_GROUP_HPP
#define VNITEST_GROUP_HPP

#include<vector>//::std::vector
#include<variant>//::std::variant
#include<string_view>//::std::string_view

#include<vnitest/static_string.hpp>
#include<vnitest/regex.h>
#include<vnitest/group_dict.h>

namespace vnitest::detail{

template<typename StaticString__>
struct Group;

}//namespace vnitest::detail

#define VNITEST_GROUP(...) \
    template<> \
    struct vnitest::detail::Group<VNITEST_MAKE_STATIC_STRING(__VA_ARGS__)>{ \
        using self_type=::vnitest::detail::Group< \
            VNITEST_MAKE_STATIC_STRING(__VA_ARGS__) \
        >; \
        using body_type=::std::vector< \
            ::std::variant<::std::string_view,::vnitest::RegEx> \
        >; \
        inline static body_type body_={}; \
        static void init(body_type& body); \
        inline static bool regist_flag=[](void){ \
            self_type::init(self_type::body_); \
            return ::vnitest::GroupDict::regist( \
                ::std::string_view{__VA_ARGS__} \
                ,&self_type::body_ \
            ); \
        }(); \
    }; \
    void ::vnitest::detail::Group< \
        VNITEST_MAKE_STATIC_STRING(__VA_ARGS__) \
    >::init( \
        typename ::vnitest::detail::Group< \
            VNITEST_MAKE_STATIC_STRING(__VA_ARGS__) \
        >::body_type& body \
    ) \
//

#define VNITEST_GROUP_ELEMENT_CASE(...) do{ \
    body.emplace_back(::std::string_view{__VA_ARGS__}); \
}while(0) \
//

#define VNITEST_GROUP_ELEMENT_CASE_REGEX(...) do{ \
    body.emplace_back(VNITEST_MAKE_REGEX(__VA_ARGS__)); \
}while(0) \
//

#endif//VNITEST_GROUP_HPP
