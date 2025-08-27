#include"execute_case_info.h"

namespace neotest{

ExecuteCaseInfo* ExecuteCaseInfo::current_=nullptr;

ExecuteCaseInfo::ExecuteCaseInfo(std::string_view case_name)noexcept
    :case_name_(case_name)
    ,group_name_({})
    ,timer_({})
    ,runtime_check_total_(0)
    ,runtime_check_passed_(0)
    ,runtime_check_failed_(0)
    ,runtime_check_failed_errors_({})
    ,runtime_assert_total_(0)
    ,runtime_assert_passed_(0)
    ,runtime_assert_failed_(0)
    ,runtime_assert_failed_exception_({})
    ,runtime_exceptions_({})
    ,skip_reason_({})
{}
//case name
ExecuteCaseInfo& ExecuteCaseInfo::set_case_name(std::string_view case_name)noexcept{
    this->case_name_=case_name;
    return *this;
}
std::string_view ExecuteCaseInfo::get_case_name(void)const noexcept{
    return this->case_name_;
}
//group name
bool ExecuteCaseInfo::has_group_name(void)const noexcept{
    return this->group_name_.has_value();
}
ExecuteCaseInfo& ExecuteCaseInfo::set_group_name(std::string_view group_name)noexcept{
    this->group_name_=group_name;
    return *this;
}
std::string_view ExecuteCaseInfo::get_group_name(void)const noexcept{
    return this->group_name_.value();
}
//execute time info
ExecuteCaseInfo& ExecuteCaseInfo::execute_start(void)noexcept{
    this->timer_.start();
    return *this;
}
ExecuteCaseInfo& ExecuteCaseInfo::execute_stop(void)noexcept{
    this->timer_.stop();
    return *this;
}
double ExecuteCaseInfo::get_duration_ns(void)const noexcept{
    return this->timer_.delta_nanoseconds();
}
std::string ExecuteCaseInfo::get_duration_string(void)const noexcept{
    return this->timer_.delta_string();
}
//runtime check
bool ExecuteCaseInfo::has_runtime_check_failed_errors(void)const noexcept{
    return !(this->runtime_check_failed_errors_.empty());
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_check_total_increment(void)noexcept{
    ++(this->runtime_check_total_);
    return *this;
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_check_passed_increment(void)noexcept{
    ++(this->runtime_check_passed_);
    return *this;
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_check_failed_increment(void)noexcept{
    ++(this->runtime_check_failed_);
    return *this;
}
std::size_t ExecuteCaseInfo::get_runtime_check_total(void)const noexcept{
    return this->runtime_check_total_;
}
std::size_t ExecuteCaseInfo::get_runtime_check_passed(void)const noexcept{
    return this->runtime_check_passed_;
}
std::size_t ExecuteCaseInfo::get_runtime_check_failed(void)const noexcept{
    return this->runtime_check_failed_;
}
double ExecuteCaseInfo::get_runtime_check_passed_rate(void)const noexcept{
    return this->runtime_check_total_>0
        ?static_cast<double>(this->runtime_check_passed_)
            /this->runtime_check_total_
        :0.0;
}
//runtime check failed errors
ExecuteCaseInfo& ExecuteCaseInfo::runtime_check_failed_errors_push_back(
    neotest::RuntimeCheckFailedError const& error
)noexcept{
    this->runtime_check_failed_errors_.emplace_back(error);
    return *this;
}
ExecuteCaseInfo const& ExecuteCaseInfo::runtime_check_failed_errors_foreach(
    std::function<void(neotest::RuntimeCheckFailedError const&)>const& func
)const noexcept{
    for(auto const& error:this->runtime_check_failed_errors_){
        func(error);
    }
    return *this;
}
//runtime assert
ExecuteCaseInfo& ExecuteCaseInfo::runtime_assert_total_increment(void)noexcept{
    ++(this->runtime_assert_total_);
    return *this;
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_assert_passed_increment(void)noexcept{
    ++(this->runtime_assert_passed_);
    return *this;
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_assert_failed_increment(void)noexcept{
    ++(this->runtime_assert_failed_);
    return *this;
}
std::size_t ExecuteCaseInfo::get_runtime_assert_total(void)const noexcept{
    return this->runtime_assert_total_;
}
std::size_t ExecuteCaseInfo::get_runtime_assert_passed(void)const noexcept{
    return this->runtime_assert_passed_;
}
std::size_t ExecuteCaseInfo::get_runtime_assert_failed(void)const noexcept{
    return this->runtime_assert_failed_;
}
double ExecuteCaseInfo::get_runtime_assert_passed_rate(void)const noexcept{
    return this->runtime_assert_total_>0
        ?static_cast<double>(this->runtime_assert_passed_)
            /this->runtime_assert_total_
        :0.0;
}
//runtime assert failed exception
ExecuteCaseInfo& ExecuteCaseInfo::set_runtime_assert_failed_exception(
    neotest::RuntimeAssertFailedException const& exception
)noexcept{
    this->runtime_assert_failed_exception_=exception;
    return *this;
}
bool ExecuteCaseInfo::has_runtime_assert_failed_exception(void)const noexcept{
    return this->runtime_assert_failed_exception_.has_value();
}
neotest::RuntimeAssertFailedException const&
ExecuteCaseInfo::get_runtime_assert_failed_exception(void)const noexcept{
    return this->runtime_assert_failed_exception_.value();
}
//runtime exception
bool ExecuteCaseInfo::has_runtime_exceptions(void)const noexcept{
    return !(this->runtime_exceptions_.empty());
}
ExecuteCaseInfo& ExecuteCaseInfo::runtime_exceptions_push_back(
    std::string const& exception_what
)noexcept{
    this->runtime_exceptions_.emplace_back(exception_what);
    return *this;
}
ExecuteCaseInfo const& ExecuteCaseInfo::runtime_exceptions_foreach(
    std::function<void(std::string const&)>const& func
)const noexcept{
    for(auto const& exception_what:this->runtime_exceptions_){
        func(exception_what);
    }
    return *this;
}
//state
ExecuteCaseInfo::State ExecuteCaseInfo::get_state(void)const noexcept{
    if(this->is_skipped()){
        return ExecuteCaseInfo::State::Skipped;
    }
    if(this->is_failed()){
        return ExecuteCaseInfo::State::Failed;
    }
    return ExecuteCaseInfo::State::Passed;
}
bool ExecuteCaseInfo::is_passed(void)const noexcept{
    return (!this->is_failed())&&(!this->is_skipped());
}
bool ExecuteCaseInfo::is_failed(void)const noexcept{
    if(this->is_skipped()){
        return false;
    }
    return this->has_runtime_check_failed_errors()
        || this->has_runtime_assert_failed_exception()
        || this->has_runtime_exceptions();
}
bool ExecuteCaseInfo::is_skipped(void)const noexcept{
    return this->has_skip_reason();
}
//skip
ExecuteCaseInfo& ExecuteCaseInfo::set_skip(std::string const& reason)noexcept{
    this->skip_reason_=reason;
    return *this;
}
bool ExecuteCaseInfo::has_skip_reason(void)const noexcept{
    return this->skip_reason_.has_value();
}
std::string const& ExecuteCaseInfo::get_skip_reason(void)const noexcept{
    return this->skip_reason_.value();
}
//current
void ExecuteCaseInfo::set_current(ExecuteCaseInfo& info)noexcept{
    ExecuteCaseInfo::current_=&info;
}
ExecuteCaseInfo& ExecuteCaseInfo::get_current(void)noexcept{
    return *(ExecuteCaseInfo::current_);
}

}//namespace neotest
