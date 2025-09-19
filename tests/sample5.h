#ifndef SAMPLE_5_H
#define SAMPLE_5_H

#include<vnitest/vnitest.h>

#ifdef TEST_SAMPLE_5

VNITEST_STATIC_CHECK("global scope",false);

void sample5_func(void)noexcept{
    VNITEST_STATIC_CHECK("global function scope",false);
    [](){
        VNITEST_STATIC_CHECK("lambda scope in global function",false);
    }();
    struct LocalClass{
//        VNITEST_STATIC_CHECK("local class scope in global function",false);
    };
}

auto lambda_func=[](){
    VNITEST_STATIC_CHECK("global lambda scope",false);
};

class Sample5_Class{
    VNITEST_STATIC_CHECK("global class scope",false);
    struct LocalClass{
        VNITEST_STATIC_CHECK("local class scope in global class",false);
    };
    void member_func(void)noexcept{
        VNITEST_STATIC_CHECK("global class member function scope",false);
        [](){
            VNITEST_STATIC_CHECK("lambda scope in global class member function",false);
        }();
        struct LocalClass{
//            VNITEST_STATIC_CHECK("local class scope in global class member function",false);
        };
    }
};

namespace tests{

VNITEST_STATIC_CHECK("namesapce scope",false);

void sample5_func(void)noexcept{
    VNITEST_STATIC_CHECK("namesapce function scope",false);
    [](){
        VNITEST_STATIC_CHECK("lambda scope in namesapce function",false);
    }();
    struct LocalClass{
//        VNITEST_STATIC_CHECK("local class scope in namesapce function",false);
    };
}

auto lambda_func=[](){
    VNITEST_STATIC_CHECK("namesapce lambda scope",false);
};

class Sample5_Class{
    VNITEST_STATIC_CHECK("namesapce class scope",false);
    struct LocalClass{
        VNITEST_STATIC_CHECK("local class scope in namesapce class",false);
    };
    void member_func(void)noexcept{
        VNITEST_STATIC_CHECK("namesapce class member function scope",false);
        [](){
            VNITEST_STATIC_CHECK("lambda scope in namesapce class member function",false);
        }();
        struct LocalClass{
//            VNITEST_STATIC_CHECK("local class scope in namesapce class member function",false);
        };
    }
};

}//namespace tests

#endif

#endif//SAMPLE_5_H
