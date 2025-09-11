#include"accumulative_timer.h"

#include<chrono>//::std::chrono

namespace neotest{

AccumulativeTimer::AccumulativeTimer(void)noexcept
    :state_(State::STOPPED)
    ,total_duration_(0)
{}
void AccumulativeTimer::start(void)noexcept{
    //从暂停或停止状态恢复运行
    if(this->state_!=State::RUNNING){
        this->start_time_=::std::chrono::high_resolution_clock::now();
        this->state_=State::RUNNING;
    }
    //如果已经在运行,则忽略
}
void AccumulativeTimer::pause(void)noexcept{
    if(this->state_==State::RUNNING){
        this->total_duration_+=
            ::std::chrono::duration_cast<::std::chrono::nanoseconds>(
                ::std::chrono::high_resolution_clock::now()-this->start_time_
            ).count();
        this->state_=State::PAUSED;
    }
    //如果已经暂停或停止,则忽略
}
void AccumulativeTimer::stop(void)noexcept{
    this->state_=State::STOPPED;
    this->total_duration_=0;
}
double AccumulativeTimer::get_elapsed_time(void)const noexcept{
    auto current_total=this->total_duration_;
    if(this->state_==State::RUNNING){
        current_total+=
            ::std::chrono::duration_cast<::std::chrono::nanoseconds>(
                ::std::chrono::high_resolution_clock::now()-this->start_time_
            ).count();
    }
    return current_total;
}
AccumulativeTimer::State AccumulativeTimer::get_state(void)const noexcept{
    return this->state_;
}
void AccumulativeTimer::reset(void)noexcept{
    if(this->state_==State::RUNNING){
        this->start_time_=::std::chrono::high_resolution_clock::now();
    }
    this->total_duration_=0;
}

}//namespace neotest
