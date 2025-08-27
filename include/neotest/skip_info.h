#ifndef NEOTEST_SKIP_INFO_H
#define NEOTEST_SKIP_INFO_H

#include<string_view>//std::string_view

namespace neotest{

struct SkipInfo{
    std::string_view file,line,info;
};

}//namespace neotest

#endif//NEOTEST_SKIP_INFO_H
