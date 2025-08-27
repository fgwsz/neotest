#include"execute.h"

#include<format>//std::format

#include"case_dict.h"
#include"execute_case_info.h"

namespace neotest{

neotest::ExecuteCaseInfo execute_case(
    std::string_view case_name
)noexcept{
    auto& case_dict=neotest::CaseDict::get();
    if(!case_dict.contains(case_name)){
        return neotest::ExecuteCaseInfo{};
    }
    auto const& case_body=case_dict.get(case_name);
    neotest::ExecuteCaseInfo ci;
    neotest::ExecuteCaseInfo::set_current(ci);
    ci.set_case_name(case_name)
        .execute_start();
    try{
        case_body();
    }catch(
        neotest::RuntimeAssertFailedException const&
        runtime_assert_failed_exception
    ){
        ci.set_runtime_assert_failed_exception(
            runtime_assert_failed_exception
        );
    }catch(std::exception const& std_exception){
        ci.set_runtime_exception(
            std::format("std::exception{{{}}}",std_exception.what())
        );
    }catch(char const* c_str){
        ci.set_runtime_exception(
            std::format("char const*{{{}}}",c_str)
        );
    }catch(std::string_view std_sv){
        ci.set_runtime_exception(
            std::format("std::string_view{{{}}}",std_sv)
        );
    }catch(std::string const& std_str){
        ci.set_runtime_exception(
            std::format("std::string{{{}}}",std_str)
        );
    }catch(...){
        ci.set_runtime_exception(
            "Unknown{...}"
        );
    }
    ci.execute_stop();
    return ci;
}

}//namespace neotest
