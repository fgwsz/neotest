#include"timer.h"

#include<ratio>//::std::ratio
#include<chrono>//::std::chrono
#include<string>//::std::string
#include<format>//::std::format
#include<array>//::std::array

namespace neotest::detail{

template<typename Period__,typename TimePoint__>
constexpr double
duration(TimePoint__ const& begin,TimePoint__ const& end)noexcept{
    return ::std::chrono::duration_cast<
        ::std::chrono::duration<double,Period__>
    >(end-begin).count();
}
::std::string nanoseconds_to_string(double ns)noexcept{
    struct TimeUnit{
        unsigned long long factor;
        char const* suffix;
    };
    static constexpr ::std::array<TimeUnit,6> time_units={{
       {3600'000'000'000,"h" },//1 h
       {60'000'000'000  ,"m" },//1 m
       {1'000'000'000   ,"s" },//1 s
       {1'000'000       ,"ms"},//1 ms
       {1'000           ,"us"},//1 us
       {1               ,"ns"} //1 ns
    }};
    if(ns==0.0){
        return "0 ns";
    }
    ::std::string ret={};
    if(ns<0.0){
        ret+='-';
        ns=-ns;
    }
    bool first=true;
    double value=0.0;
    for(auto const& unit:time_units){
        if(ns<unit.factor){
            continue;
        }
        value=static_cast<double>(
            static_cast<unsigned long long>(ns)/unit.factor
        );
        ns-=value*unit.factor;
        if(!first){
            ret+=" ";
        }
        first=false;
        ret+=::std::format(
            "{} {}",static_cast<unsigned long long>(value),unit.suffix
        );
    }
    return ret;
}

}//namespace ::neotest::detail

namespace neotest{

void Timer::start()noexcept{
    this->begin_=clock::now();
}
void Timer::stop()noexcept{
    this->end_=clock::now();
}
double Timer::duration_nanoseconds()const noexcept{
    return ::neotest::detail::duration<::std::nano,Timer::time_point>(
        this->begin_,this->end_
    );
}
double Timer::duration_microseconds()const noexcept{
    return ::neotest::detail::duration<::std::micro,Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::duration_milliseconds()const noexcept{
    return ::neotest::detail::duration<::std::milli,Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::duration_seconds()const noexcept{
    return ::neotest::detail::duration<::std::ratio<1>,Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::duration_minutes()const noexcept{
    return ::neotest::detail::duration<::std::ratio<60>,Timer::time_point>
        (this->begin_,this->end_);
}
double Timer::duration_hours()const noexcept{
    return ::neotest::detail::duration<::std::ratio<3600>,Timer::time_point>
        (this->begin_,this->end_);
}
::std::string Timer::duration_string()const noexcept{
    return ::neotest::detail::nanoseconds_to_string(duration_nanoseconds());
}

}//namespace neotest
