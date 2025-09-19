#ifndef SAMPLE_9_H
#define SAMPLE_9_H

#include<neotest/neotest.h>

void test_sample_9(void)noexcept{
    ::neotest::Timer timer;
    timer.start();
    for(auto i=0;i<1000'0000;++i){}
    timer.stop();
    ::std::cout<<::std::format(
        "duration ns    :{}\n"
        "duration us    :{}\n"
        "duration ms    :{}\n"
        "duration s     :{}\n"
        "duration m     :{}\n"
        "duration h     :{}\n"
        "duration string:{}\n"
        ,timer.duration_nanoseconds()
        ,timer.duration_microseconds()
        ,timer.duration_milliseconds()
        ,timer.duration_seconds()
        ,timer.duration_minutes()
        ,timer.duration_hours()
        ,timer.duration_string()
    );
}

#endif//SAMPLE_9_H
