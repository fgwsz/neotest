#ifndef NEOTEST_SKIP_H
#define NEOTEST_SKIP_H

#include"macro.h"
#include"skip_info.h"

namespace neotest{

void skip(neotest::SkipInfo const& si)noexcept;

}//namespace neotest

#define NEOTEST_SKIP(...) do{ \
    neotest::skip( \
        neotest::SkipInfo{ \
            std::string_view{__FILE__} \
            ,std::string_view{NEOTEST_TO_STRING(__LINE__)} \
            ,std::string_view{__VA_ARGS__} \
        } \
    ); \
    return; \
}while(0) \
//

#endif//NEOTEST_SKIP_H
