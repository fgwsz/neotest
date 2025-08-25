#ifndef NEOTEST_TIMER_H
#define NEOTEST_TIMER_H

#include<string>//std::string
#include<chrono>//std::chrono

namespace neotest{

class Timer{
public:
    void start(void)noexcept;
    void stop(void)noexcept;
    double delta_nanoseconds(void)const noexcept;
    double delta_microseconds(void)const noexcept;
    double delta_milliseconds(void)const noexcept;
    double delta_seconds(void)const noexcept;
    double delta_minutes(void)const noexcept;
    double delta_hours(void)const noexcept;
    std::string delta_string(void)const noexcept;
private:
    using clock=std::chrono::high_resolution_clock;
    using time_point=typename clock::time_point;
    time_point begin_,end_;
};

}//namespace neotest

#endif//NEOTEST_TIMER_H
