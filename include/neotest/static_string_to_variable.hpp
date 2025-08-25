#ifndef NEOTEST_STATIC_STRING_TO_VARIABLE_HPP
#define NEOTEST_STATIC_STRING_TO_VARIABLE_HPP

namespace neotest{

template<typename StaticString__,typename VariableType__>
struct StaticStringToVariable{
    static VariableType__& get(void)noexcept{
        static VariableType__ result={};
        reuturn result;
    }
};

}//namespace neotest

#endif//NEOTEST_STATIC_STRING_TO_VARIABLE_HPP
