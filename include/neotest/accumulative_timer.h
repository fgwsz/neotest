#ifndef NEOTEST_ACCUMULATIVE_TIMER_H
#define NEOTEST_ACCUMULATIVE_TIMER_H

#include<chrono>//::std::chrono

namespace neotest{

class AccumulativeTimer{
public:
    enum class State{
        STOPPED,//已停止
        RUNNING,//运行中
        PAUSED  //已暂停
    };
    AccumulativeTimer(void)noexcept;
    //开始计时
    void start(void)noexcept;
    //暂停计时
    void pause(void)noexcept;
    //停止计时并重置
    void stop(void)noexcept;
    //获取当前累计时间(纳秒)
    double get_elapsed_time(void)const noexcept;
    //获取当前状态
    State get_state(void)const noexcept;
    //重置计时器(清除累计时间)
    void reset(void)noexcept;
private:
    ::std::chrono::high_resolution_clock::time_point start_time_;
    double total_duration_;
    State state_;
};

}//namespace neotest

#endif//NEOTEST_ACCUMULATIVE_TIMER_H
