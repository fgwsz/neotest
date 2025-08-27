#include"main.h"

#include<format>//std::format

#include"neotest/neotest.h"

NEOTEST_CASE("Hello"){
    NEOTEST_RUNTIME_CHECK_EQ(0,0-3);
    NEOTEST_RUNTIME_CHECK_EQ(1,1-3);
    NEOTEST_RUNTIME_CHECK_EQ(2,2-3);
    NEOTEST_SKIP("this is skip reason!");
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2);
}
NEOTEST_CASE("world!"){
    NEOTEST_RUNTIME_CHECK_EQ(1+2,2);
}
std::string execute_case_info_to_string(
    neotest::ExecuteCaseInfo const& ei
)noexcept{
    auto var_str=[](std::string const& name,auto const& value){
        return std::format("\"{}\": {}\n",name,value);
    };
    std::string ret=var_str("case_name",ei.get_case_name());
    if(ei.has_group_name()){
        ret.append(var_str("group_name",ei.get_group_name()));
    }
    ret.append(var_str("duration",ei.get_duration_string()));
    ret.append(var_str("runtime_check_total",ei.get_runtime_check_total()));
    ret.append(var_str("runtime_check_passed",ei.get_runtime_check_passed()));
    ret.append(var_str("runtime_check_failed",ei.get_runtime_check_failed()));
    ret.append(var_str("runtime_check_passed_rate",
        ei.get_runtime_check_passed_rate()));

    if(ei.has_runtime_check_failed_errors()){
        std::size_t index=0;
        auto func=[&](auto const& error){
            ret.append(
                var_str(
                    std::format("runtime_check_failed_errors[{}].file",index),
                    error.file
                )
            );
            ret.append(
                var_str(
                    std::format("runtime_check_failed_errors[{}].line",index),
                    error.line
                )
            );
            ret.append(
                var_str(
                    std::format("runtime_check_failed_errors[{}].info",index),
                    error.info
                )
            );
            ++index;
        };
        ei.runtime_check_failed_errors_foreach(func);
    }

    ret.append(var_str("runtime_assert_total",ei.get_runtime_assert_total()));
    ret.append(var_str("runtime_assert_passed",ei.get_runtime_assert_passed()));
    ret.append(var_str("runtime_assert_failed",ei.get_runtime_assert_failed()));
    ret.append(var_str("runtime_assert_passed_rate",
        ei.get_runtime_assert_passed_rate()));

    if(ei.has_runtime_assert_failed_exception()){
        auto const& exception=ei.get_runtime_assert_failed_exception();
        ret.append(var_str("runtime_assert_failed_exception.file",exception.file()));
        ret.append(var_str("runtime_assert_failed_exception.line",exception.line()));
        ret.append(var_str("runtime_assert_failed_exception.info",exception.info()));
    }

    if(ei.has_runtime_exception()){
        ret.append(var_str("runtime_exception",ei.get_runtime_exception()));
    }

    ret.append(var_str("is_passed",ei.is_passed()));
    ret.append(var_str("is_failed",ei.is_failed()));
    ret.append(var_str("is_skipped",ei.is_skipped()));
    ret.append(var_str("is_undefined",ei.is_undefined()));

    if(ei.has_skip()){
        ret.append(var_str("skip.file",ei.get_skip().file));
        ret.append(var_str("skip.line",ei.get_skip().line));
        ret.append(var_str("skip.info",ei.get_skip().info));
    }
    return ret;
}
int main(int argc,char* argv[]){
    neotest::Timer t;
    t.start();
    std::cout<<"hello world!\n";
    t.stop();
    std::cout<<t.delta_string()<<'\n';
    auto ei=neotest::execute_case("Hello");
    std::cout<<execute_case_info_to_string(ei);
    return 0;
}
