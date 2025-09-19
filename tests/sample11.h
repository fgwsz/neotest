#ifndef SAMPLE_11_H
#define SAMPLE_11_H

#include<vnitest/vnitest.h>

#include<iostream>//::std::cout
#include<thread>//::std::this_thread
#include<chrono>//::std::chrono

void test_timer_1(void)noexcept{
    ::vnitest::Timer timer;
    //开始计时
    ::std::cout<<"计时开始...\n";
    timer.start();
    //模拟一些工作
    ::std::this_thread::sleep_for(::std::chrono::seconds(5));
    //暂停计时
    timer.stop();
    ::std::cout
        <<::std::format("已暂停,累计时间: {}\n",timer.duration_string());
    //模拟暂停期间
    ::std::this_thread::sleep_for(::std::chrono::seconds(2));
    //恢复计时
    ::std::cout<<"恢复计时...\n";
    timer.start();
    //模拟更多工作
    ::std::this_thread::sleep_for(::std::chrono::seconds(3));
    //停止计时
    timer.stop();
    ::std::cout<<"停止计时...\n";
    //获取最终时间
    ::std::cout
        <<::std::format("最终累计时间: {}\n",timer.duration_string());
}
void test_timer_2(void)noexcept{
    ::vnitest::Timer timer;
    //开始计时
    ::std::cout<<"计时开始...\n";
    timer.start();
    //模拟一些工作
    ::std::this_thread::sleep_for(::std::chrono::seconds(5));
    //暂停计时
    timer.stop();
    ::std::cout
        <<::std::format("已暂停,累计时间: {}\n",timer.duration_string());
    //模拟暂停期间
    ::std::this_thread::sleep_for(::std::chrono::seconds(2));
    //恢复计时
    ::std::cout<<"恢复计时...\n";
    timer.start();
    //重置计时
    ::std::cout<<"重置计时...\n";
    timer.reset();
    //模拟更多工作
    ::std::this_thread::sleep_for(::std::chrono::seconds(3));
    //停止计时
    timer.stop();
    ::std::cout<<"停止计时...\n";
    //获取最终时间
    ::std::cout
        <<::std::format("最终累计时间: {}\n",timer.duration_string());
}

void test_sample_11(void)noexcept{
    ::test_timer_1();
    ::test_timer_2();
}

#endif//SAMPLE_11_H
