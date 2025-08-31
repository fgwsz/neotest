#ifndef SAMPLE_5_H
#define SAMPLE_5_H

#include"neotest/static_check.hpp"

#ifdef TEST_SAMPLE_5

NEOTEST_STATIC_CHECK("global space",false);

void sample5_func(void)noexcept{
    NEOTEST_STATIC_CHECK("function space",false);
}

class Sample5_Class{
    NEOTEST_STATIC_CHECK("class space",false);
};

#endif

#endif//SAMPLE_5_H
