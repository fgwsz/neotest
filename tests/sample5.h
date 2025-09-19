#ifndef SAMPLE_5_H
#define SAMPLE_5_H

#include<neotest/neotest.h>

#ifdef TEST_SAMPLE_5

NEOTEST_STATIC_CHECK("global scope",false);

void sample5_func(void)noexcept{
    NEOTEST_STATIC_CHECK("global function scope",false);
    [](){
        NEOTEST_STATIC_CHECK("lambda scope in global function",false);
    }();
    struct LocalClass{
//        NEOTEST_STATIC_CHECK("local class scope in global function",false);
    };
}

auto lambda_func=[](){
    NEOTEST_STATIC_CHECK("global lambda scope",false);
};

class Sample5_Class{
    NEOTEST_STATIC_CHECK("global class scope",false);
    struct LocalClass{
        NEOTEST_STATIC_CHECK("local class scope in global class",false);
    };
    void member_func(void)noexcept{
        NEOTEST_STATIC_CHECK("global class member function scope",false);
        [](){
            NEOTEST_STATIC_CHECK("lambda scope in global class member function",false);
        }();
        struct LocalClass{
//            NEOTEST_STATIC_CHECK("local class scope in global class member function",false);
        };
    }
};

namespace tests{

NEOTEST_STATIC_CHECK("namesapce scope",false);

void sample5_func(void)noexcept{
    NEOTEST_STATIC_CHECK("namesapce function scope",false);
    [](){
        NEOTEST_STATIC_CHECK("lambda scope in namesapce function",false);
    }();
    struct LocalClass{
//        NEOTEST_STATIC_CHECK("local class scope in namesapce function",false);
    };
}

auto lambda_func=[](){
    NEOTEST_STATIC_CHECK("namesapce lambda scope",false);
};

class Sample5_Class{
    NEOTEST_STATIC_CHECK("namesapce class scope",false);
    struct LocalClass{
        NEOTEST_STATIC_CHECK("local class scope in namesapce class",false);
    };
    void member_func(void)noexcept{
        NEOTEST_STATIC_CHECK("namesapce class member function scope",false);
        [](){
            NEOTEST_STATIC_CHECK("lambda scope in namesapce class member function",false);
        }();
        struct LocalClass{
//            NEOTEST_STATIC_CHECK("local class scope in namesapce class member function",false);
        };
    }
};

}//namespace tests

#endif

#endif//SAMPLE_5_H
