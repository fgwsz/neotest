#include"timer.h"

#include<cmath>//std::floor

#include<ratio>//std::ratio
#include<chrono>//std::chrono
#include<string>//std::to_string

using namespace neotest;

template<typename Period,typename TimePoint>
static double delta_(TimePoint const& begin,TimePoint const& end)noexcept{
    return std::chrono::duration_cast<
        std::chrono::duration<double,Period>
    >(end-begin).count();
}
static std::string nanoseconds_to_string_(double ns)noexcept{
    constexpr double c_1ns=1;
    constexpr double c_1us=1000*c_1ns;
    constexpr double c_1ms=1000*c_1us;
    constexpr double c_1s=1000*c_1ms;
    constexpr double c_1m=60*c_1s;
    constexpr double c_1h=60*c_1m;
    double integer=0;
    double others=0;
    if(ns>=c_1h){
        integer=std::floor(ns/c_1h);
        others=ns-integer*c_1h;
        return std::to_string(static_cast<std::size_t>(integer))+" h "
            +::nanoseconds_to_string_(others);
    }else if(ns>=c_1m){
        integer=std::floor(ns/c_1m);
        others=ns-integer*c_1m;
        return std::to_string(static_cast<std::size_t>(integer))+" m "
            +::nanoseconds_to_string_(others);
    }else if(ns>=c_1s){
        integer=std::floor(ns/c_1s);
        others=ns-integer*c_1s;
        return std::to_string(static_cast<std::size_t>(integer))+" s "
            +::nanoseconds_to_string_(others);
    }else if(ns>=c_1ms){
        integer=std::floor(ns/c_1ms);
        others=ns-integer*c_1ms;
        return std::to_string(static_cast<std::size_t>(integer))+" ms "
            +::nanoseconds_to_string_(others);
    }else if(ns>=c_1us){
        integer=std::floor(ns/c_1us);
        others=ns-integer*c_1us;
        return std::to_string(static_cast<std::size_t>(integer))+" us "
            +::nanoseconds_to_string_(others);
    }
    return std::to_string(static_cast<std::size_t>(ns))+" ns";
}

void Timer::start(void)noexcept{
    this->begin_=Timer::clock::now();
}
void Timer::stop(void)noexcept{
    this->end_=Timer::clock::now();
}
double Timer::delta_nanoseconds(void)const noexcept{
    return ::delta_<std::nano,typename Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::delta_microseconds(void)const noexcept{
    return ::delta_<std::micro,typename Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::delta_milliseconds(void)const noexcept{
    return ::delta_<std::milli,typename Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::delta_seconds(void)const noexcept{
    return ::delta_<std::ratio<1>,typename Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::delta_minutes(void)const noexcept{
    return ::delta_<std::ratio<60>,typename Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::delta_hours(void)const noexcept{
    return
        ::delta_<std::ratio<3600>,typename Timer::time_point>
        (this->begin_,this->end_);
}
std::string Timer::delta_string(void)const noexcept{
    return ::nanoseconds_to_string_(this->delta_nanoseconds());
}
