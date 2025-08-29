#ifndef NEOTEST_SKIP_H
#define NEOTEST_SKIP_H

#include"macro.h"
#include"source_info.h"
#include"skip_stream.hpp"

//...: string variable
#define NEOTEST_SKIP(...) \
    ::neotest::SkipStream(NEOTEST_MAKE_SOURCE_INFO(__VA_ARGS__)) \
//

#endif//NEOTEST_SKIP_H
