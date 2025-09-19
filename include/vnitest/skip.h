#ifndef VNITEST_SKIP_H
#define VNITEST_SKIP_H

#include<vnitest/source_info.h>
#include<vnitest/skip_stream.hpp>

//...: string variable
#define VNITEST_SKIP(...) \
    ::vnitest::SkipStream(VNITEST_MAKE_SOURCE_INFO(__VA_ARGS__)) \
//

#endif//VNITEST_SKIP_H
