#ifndef VNITEST_TIMER_H
#define VNITEST_TIMER_H

#include<string>//::std::string
#include<chrono>//::std::chrono

namespace vnitest{

class Timer{
public:
    Timer(Timer const&)noexcept=default;
    Timer(Timer&&)noexcept=default;
    Timer& operator=(Timer const&)noexcept=default;
    Timer& operator=(Timer&&)noexcept=default;
    ~Timer(void)noexcept=default;

    Timer(void)noexcept;
    //开始计时/结束暂停继续计时
    void start(void)noexcept;
    //暂停计时/停止计时
    void stop(void)noexcept;
    //重置累计时间但不改变当前计时器状态
    void reset(void)noexcept;
    //获取当前累计时间
    double duration_nanoseconds(void)const noexcept;
    double duration_microseconds(void)const noexcept;
    double duration_milliseconds(void)const noexcept;
    double duration_seconds(void)const noexcept;
    double duration_minutes(void)const noexcept;
    double duration_hours(void)const noexcept;
    //累计时间打印相关
    static ::std::string nanoseconds_to_string(double ns)noexcept;
    ::std::string duration_string(void)const noexcept;
    //计时器状态
    enum class State{
        STOPPED,//已停止
        RUNNING //运行中
    };
    //获取当前状态
    State get_state(void)const noexcept;
    bool is_stopped(void)const noexcept;
    bool is_running(void)const noexcept;
private:
    ::std::chrono::steady_clock::time_point start_time_;
    double total_duration_;
    State state_;
};

}//namespace vnitest

#endif//VNITEST_TIMER_H
