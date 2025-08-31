#ifndef SAMPLE_4_H
#define SAMPLE_4_H

#include<iostream>//::std::cout

#include"neotest/type_name_of.hpp"

void test_sample_4(void)noexcept{
    auto println_type_name=[&]<typename Type__>(void)noexcept{
        ::std::cout<<::neotest::type_name_of<Type__>()<<'\n';
    };
    println_type_name.template operator()<bool>();
    println_type_name.template operator()<char>();
    println_type_name.template operator()<signed char>();
    println_type_name.template operator()<unsigned char>();
    println_type_name.template operator()<wchar_t>();
    println_type_name.template operator()<short>();
    println_type_name.template operator()<unsigned short>();
    println_type_name.template operator()<int>();
    println_type_name.template operator()<unsigned int>();
    println_type_name.template operator()<long>();
    println_type_name.template operator()<unsigned long>();
    println_type_name.template operator()<long long>();
    println_type_name.template operator()<unsigned long long>();
    println_type_name.template operator()<float>();
    println_type_name.template operator()<double>();
    println_type_name.template operator()<::std::string_view>();
    println_type_name.template operator()<::std::string>();
    println_type_name.template operator()<
        void(*
            (
                ::std::string::* const(*const)[1]
            )(...)const volatile && noexcept
        )(int(&)[2][3])noexcept
    >();
}

#endif//SAMPLE_4_H
