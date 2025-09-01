#ifndef NEOTEST_GROUP_HPP
#define NEOTEST_GROUP_HPP

#include<vector>//::std::vector
#include<variant>//::std::variant
#include<string_view>//::std::string_view
#include<regex>//::std::regex
#include<tuple>//::std::tuple

#include"static_string.hpp"
#include"regex.h"
#include"group_dict.h"

namespace neotest::detail{

template<typename StaticString__>
struct Group;

}//namespace neotest::detail

#define NEOTEST_GROUP(...) \
    template<> \
    struct neotest::detail::Group<NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__)>{ \
        using self_type=::neotest::detail::Group< \
            NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__) \
        >; \
        using body_type=::std::vector< \
            ::std::variant<::std::string_view,::neotest::RegEx> \
        >; \
        inline static body_type body_={}; \
        static void init(body_type& body); \
        inline static bool regist_flag=[](void){ \
            self_type::init(self_type::body_); \
            return ::neotest::GroupDict::regist( \
                ::std::string_view{__VA_ARGS__} \
                ,&self_type::body_ \
            ); \
        }(); \
    }; \
    void ::neotest::detail::Group< \
        NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__) \
    >::init( \
        typename ::neotest::detail::Group< \
            NEOTEST_MAKE_STATIC_STRING(__VA_ARGS__) \
        >::body_type& body \
    ) \
//

#define NEOTEST_GROUP_ELEMENT_CASE(...) do{ \
    body.emplace_back(::std::string_view{__VA_ARGS__}); \
}while(0) \
//

#define NEOTEST_GROUP_ELEMENT_CASE_REGEX(...) do{ \
    body.emplace_back(NEOTEST_MAKE_REGEX(__VA_ARGS__)); \
}while(0) \
//

#endif//NEOTEST_GROUP_HPP
