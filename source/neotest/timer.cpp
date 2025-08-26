#include"timer.h"

#include<cmath>//std::floor

#include<ratio>//std::ratio
#include<chrono>//std::chrono
#include<string>//std::string std::to_string
#include<array>//std::array
#include<sstream>//std::ostringstream

namespace neotest::detail{

template<typename Period,typename TimePoint>
constexpr double delta(TimePoint const& begin,TimePoint const& end)noexcept{
    return std::chrono::duration_cast<
        std::chrono::duration<double,Period>
    >(end-begin).count();
}
std::string nanoseconds_to_string(double ns)noexcept{
    struct TimeUnit{
        double factor;
        const char* suffix;
    };
    static constexpr std::array<TimeUnit,6> time_units ={{
       {60.0 * 60.0 * 1000.0 * 1000.0 * 1000.0,"h"}, // 1 h
       {60.0 * 1000.0 * 1000.0 * 1000.0,"m"},        // 1 m
       {1000.0 * 1000.0 * 1000.0,"s"},               // 1 s
       {1000.0 * 1000.0,"ms"},                       // 1 ms
       {1000.0,"us"},                                // 1 us
       {1.0,"ns"}                                    // 1 ns
    }};
    if(ns == 0.0){
        return "0 ns";
    }
    std::ostringstream oss;
    bool first=true;
    for(const auto& unit:time_units){
        if(ns>=unit.factor){
            double value=std::floor(ns/unit.factor);
            ns-=value*unit.factor;
            if(!first){
                oss<<" ";
            }
            oss<<static_cast<std::size_t>(value)<<" "<<unit.suffix;
            first=false;
            if(ns<1.0){
                break;
            }
        }
    }
    return oss.str();
}

} // namespace neotest::detail

namespace neotest{

void Timer::start()noexcept{
    begin_=clock::now();
}
void Timer::stop()noexcept{
    end_=clock::now();
}
double Timer::delta_nanoseconds()const noexcept{
    return neotest::detail::delta<std::nano,time_point>(begin_,end_);
}
double Timer::delta_microseconds()const noexcept{
    return neotest::detail::delta<std::micro,time_point>(begin_,end_);
}
double Timer::delta_milliseconds()const noexcept{
    return neotest::detail::delta<std::milli,time_point>(begin_,end_);
}
double Timer::delta_seconds()const noexcept{
    return neotest::detail::delta<std::ratio<1>,time_point>(begin_,end_);
}
double Timer::delta_minutes()const noexcept{
    return neotest::detail::delta<std::ratio<60>,time_point>(begin_,end_);
}
double Timer::delta_hours()const noexcept{
    return neotest::detail::delta<std::ratio<3600>,time_point>(begin_,end_);
}
std::string Timer::delta_string()const noexcept{
    return neotest::detail::nanoseconds_to_string(delta_nanoseconds());
}

}//namespace neotest
