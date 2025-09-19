#include<vnitest/skip_stream.hpp>

#include<vnitest/skip_exception.h>
#include<vnitest/execute_case_info.h>

namespace vnitest{

SkipStream::SkipStream(::vnitest::SourceInfo const& si)noexcept
    :info_(si),message_({})
{}
SkipStream::~SkipStream(void)noexcept(false){
    auto se=::vnitest::SkipException(
        this->info_.file
        ,this->info_.line
        ,this->info_.info
    );
    if(this->message_.has_value()){
        se.set_msg(this->message_.value());
    }
    throw se;
}

}//namespace vnitest
