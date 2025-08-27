#ifndef NEOTEST_SKIP_H
#define NEOTEST_SKIP_H

#include"macro.h"
#include"skip_info.h"
#include"execute_case_info.h"

#define NEOTEST_SKIP(...) do{ \
    neotest::ExecuteCaseInfo::get_current() \
        .set_skip( \
            neotest::SkipInfo{ \
            std::string_view{__FILE__} \
            ,std::string_view{NEOTEST_TO_STRING(__LINE__)} \
            ,std::string_view{NEOTEST_TO_STRING(__VA_ARGS__)} \
        } \
    ); \
    return; \
}while(0) \
//

#endif//NEOTEST_SKIP_H
