#ifndef NEOTEST_TIMER_H
#define NEOTEST_TIMER_H

#include<string>//::std::string
#include<chrono>//::std::chrono

namespace neotest{

class Timer{
public:
    void start(void)noexcept;
    void stop(void)noexcept;
    double duration_nanoseconds(void)const noexcept;
    double duration_microseconds(void)const noexcept;
    double duration_milliseconds(void)const noexcept;
    double duration_seconds(void)const noexcept;
    double duration_minutes(void)const noexcept;
    double duration_hours(void)const noexcept;
    ::std::string duration_string(void)const noexcept;
private:
    using clock=::std::chrono::high_resolution_clock;
    using time_point=typename clock::time_point;
    time_point begin_,end_;
};

}//namespace neotest

#endif//NEOTEST_TIMER_H
