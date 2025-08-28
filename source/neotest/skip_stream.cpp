#include"skip_stream.hpp"

#include"skip_exception.h"
#include"execute_case_info.h"

namespace neotest{

SkipStream::SkipStream(neotest::SourceInfo const& si)noexcept
    :info_(si),message_({})
{}
SkipStream::~SkipStream(void)noexcept(false){
    auto se=neotest::SkipException(
        this->info_.file
        ,this->info_.line
        ,this->info_.info
    );
    if(this->message_.has_value()){
        se.set_msg(this->message_.value());
    }
    throw se;
}

}//namespace neotest
