#include"execute_group_info.h"

#include"group_dict.h"

namespace neotest{

ExecuteGroupInfo::ExecuteGroupInfo(::std::string_view name)noexcept
    :name_(name)
    ,timer_({})
    ,case_total_(0)
    ,case_passed_(0)
    ,case_failed_(0)
    ,case_skipped_(0)
    ,case_undefined_(0)
    ,data_({})
{}
//group name
ExecuteGroupInfo& ExecuteGroupInfo::set_name(::std::string_view name)noexcept{
    this->name_=name;
    return *this;
}
::std::string_view ExecuteGroupInfo::get_name(void)const noexcept{
    return this->name_;
}
//execute time info
ExecuteGroupInfo& ExecuteGroupInfo::execute_start(void)noexcept{
    this->timer_.start();
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::execute_stop(void)noexcept{
    this->timer_.stop();
    return *this;
}
double ExecuteGroupInfo::get_duration_ns(void)const noexcept{
    return this->timer_.duration_nanoseconds();
}
::std::string ExecuteGroupInfo::get_duration_string(void)const noexcept{
    return this->timer_.duration_string();
}
//case
ExecuteGroupInfo& ExecuteGroupInfo::case_total_increment(void)noexcept{
    ++(this->case_total_);
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::case_passed_increment(void)noexcept{
    ++(this->case_passed_);
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::case_failed_increment(void)noexcept{
    ++(this->case_failed_);
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::case_skipped_increment(void)noexcept{
    ++(this->case_skipped_);
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::case_undefined_increment(void)noexcept{
    ++(this->case_undefined_);
    return *this;
}
::std::size_t ExecuteGroupInfo::get_case_total(void)const noexcept{
    return this->case_total_;
}
::std::size_t ExecuteGroupInfo::get_case_passed(void)const noexcept{
    return this->case_passed_;
}
::std::size_t ExecuteGroupInfo::get_case_failed(void)const noexcept{
    return this->case_failed_;
}
::std::size_t ExecuteGroupInfo::get_case_skipped(void)const noexcept{
    return this->case_skipped_;
}
::std::size_t ExecuteGroupInfo::get_case_undefined(void)const noexcept{
    return this->case_undefined_;
}
double ExecuteGroupInfo::get_case_passed_rate(void)const noexcept{
    if(this->case_total_==0){
        return 1.0;
    }else{
        return static_cast<double>(this->case_passed_)/this->case_total_;
    }
}
//state
ExecuteGroupInfo::State ExecuteGroupInfo::get_state(void)const noexcept{
    if(this->is_passed()){
        return ExecuteGroupInfo::State::Passed;
    }else if(this->is_failed()){
        return ExecuteGroupInfo::State::Failed;
    }else if(this->is_skipped()){
        return ExecuteGroupInfo::State::Skipped;
    }
    return ExecuteGroupInfo::State::Undefined;
}
bool ExecuteGroupInfo::is_passed(void)const noexcept{
    return (!this->is_undefined())
        &&(this->case_total_==this->case_passed_);
}
bool ExecuteGroupInfo::is_failed(void)const noexcept{
    return (!this->is_undefined())
        &&(this->case_total_!=0)
        &&(this->case_failed_>0);
}
bool ExecuteGroupInfo::is_skipped(void)const noexcept{
    return (!this->is_undefined())
        &&(this->case_total_!=0)
        &&(this->case_skipped_>0);
}
bool ExecuteGroupInfo::is_undefined(void)const noexcept{
    return !(::neotest::GroupDict::get().contains(this->name_));
}
ExecuteGroupInfo& ExecuteGroupInfo::data_push_back(
    ::std::string_view case_name
    ,::neotest::ExecuteCaseInfo const& case_info
)noexcept{
    this->data_.emplace_back(case_info);
    return *this;
}
ExecuteGroupInfo& ExecuteGroupInfo::data_push_back(
    ::std::string_view case_regex_pattern
    ,::std::vector<::neotest::ExecuteCaseInfo> const& case_regex_info
)noexcept{
    this->data_.emplace_back(
        typename ExecuteGroupInfo::case_regex_info_type{
            case_regex_pattern
            ,case_regex_info
        }
    );
    return *this;
}
::std::vector<typename ExecuteGroupInfo::element_type>const&
ExecuteGroupInfo::get_data(void)const noexcept{
    return this->data_;
}

}//namespace neotest
