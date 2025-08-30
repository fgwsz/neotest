#include"execute.h"

#include<format>//::std::format
#include<regex>//::std::regex_match

#include"case_dict.h"
#include"execute_case_info.h"
#include"group_dict.h"
#include"execute_group_info.h"

namespace neotest{

::neotest::ExecuteCaseInfo execute_case(
    ::std::string_view case_name
)noexcept{
    auto& case_dict=::neotest::CaseDict::get();
    if(!case_dict.contains(case_name)){
        return ::neotest::ExecuteCaseInfo{case_name};
    }
    auto const& case_body=case_dict.get(case_name);
    ::neotest::ExecuteCaseInfo ci;
    ::neotest::ExecuteCaseInfo::set_current(ci);
    ci.set_case_name(case_name)
        .execute_start();
    try{
        case_body();
    }catch(
        ::neotest::RuntimeAssertFailedException const&
        runtime_assert_failed_exception
    ){
        ci.set_runtime_assert_failed_exception(
            runtime_assert_failed_exception
        );
    }catch(::neotest::SkipException const& skip_exception){
        ci.set_skip(skip_exception);
    }catch(::std::exception const& std_exception){
        ci.set_runtime_exception(
            ::std::format("::std::exception{{{}}}",std_exception.what())
        );
    }catch(char const* c_str){
        ci.set_runtime_exception(::std::format("char const*{{{}}}",c_str));
    }catch(::std::string_view std_sv){
        ci.set_runtime_exception(
            ::std::format("::std::string_view{{{}}}",std_sv)
        );
    }catch(::std::string const& std_str){
        ci.set_runtime_exception(
            ::std::format("::std::string{{{}}}",std_str)
        );
    }catch(...){
        ci.set_runtime_exception("Unknown{...}");
    }
    ci.execute_stop();
    return ci;
}

::std::vector<::neotest::ExecuteCaseInfo> execute_case(
    ::std::regex const& case_name_regex
)noexcept{
    ::std::vector<::neotest::ExecuteCaseInfo> ret={};
    ::neotest::CaseDict::get().foreach(
        [&](::std::string_view case_name,auto const& case_body)noexcept{
            static ::std::string name={};
            name=case_name;//::std::string_view to ::std::string
            if(::std::regex_match(name,case_name_regex)){
                ret.emplace_back(::neotest::execute_case(case_name));
            }
        }
    );
    return ret;
}

::neotest::ExecuteGroupInfo execute_group(
    ::std::string_view group_name
)noexcept{
    auto& group_dict=::neotest::GroupDict::get();
    if(!group_dict.contains(group_name)){
        return ::neotest::ExecuteGroupInfo{group_name};
    }
    auto const& group_data=*(group_dict.get(group_name));
    auto& case_dict=::neotest::CaseDict::get();
    ::neotest::ExecuteGroupInfo ei;
    auto ei_case_increment=[&](::neotest::ExecuteCaseInfo const& ci){
        ei.case_total_increment();
        if(ci.is_passed()){
            ei.case_passed_increment();
        }else if(ci.is_failed()){
            ei.case_failed_increment();
        }else if(ci.is_skipped()){
            ei.case_skipped_increment();
        }else{
            ei.case_undefined_increment();
        }
    };
    ei.set_name(group_name);
    ei.execute_start();
    for(auto const& element:group_data){
        if(std::holds_alternative<::std::string_view>(element)){
            auto const& case_name=::std::get<::std::string_view>(element);
            //
            auto ci=::neotest::execute_case(case_name);
            ci.set_group_name(ei.get_name());
            ei_case_increment(ci);
            ei.data_push_back(case_name,ci);
        }else{
            auto const& case_regex=::std::get<::neotest::RegEx>(element);
            auto ri=::neotest::execute_case(case_regex.object);
            for(auto& ci:ri){
                ci.set_group_name(ei.get_name());
                ei_case_increment(ci);
            }
            ei.data_push_back(case_regex.pattern,ri);
        }
    }
    ei.execute_stop();
    return ei;
}

::std::vector<::neotest::ExecuteGroupInfo> execute_group(
    ::std::regex const& group_name_regex
)noexcept{
    ::std::vector<::neotest::ExecuteGroupInfo> ret={};
    ::neotest::GroupDict::get().foreach(
        [&](::std::string_view group_name,auto const& group_body)noexcept{
            static ::std::string name={};
            name=group_name;//::std::string_view to ::std::string
            if(::std::regex_match(name,group_name_regex)){
                ret.emplace_back(::neotest::execute_group(group_name));
            }
        }
    );
    return ret;
}

}//namespace neotest
