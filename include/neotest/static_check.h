#ifndef NEOTEST_STATIC_CHECK_H
#define NEOTEST_STATIC_CHECK_H

namespace neotest{

//TODO
template<
    typename File_StaticString__
    ,::std::size_t line_number__
    ,bool condition__
>
inline static constexpr bool static_check_expr=condition__;

}//namespace neotest

#endif//NEOTEST_STATIC_CHECK_H
