#pragma once
//->check->assert->
//check errors
//assert exception
//check total
//
void execute_case(
    std::string_view case_name
)noexcept;

//执行测试用例的时候统计哪些信息呢?

//1.测试开始的日期和时间
//2.测试结束的日期和时间
//3.测试的总用时

//4.执行用例的个数
//5.执行用例成功的个数
//6.执行用例失败的个数
//5.执行用例成功数量的占比

//用例的名称
//用例里面实际执行的CASE语句的数量
//用例里面实际执行的CASE语句的成功数量
//用例里面实际执行的CASE语句的失败数量
//用例里面实际执行的CASE语句的成功数量所占的百分比

//用例里面实际执行的CASE语句的失败信息

//用例里面实际执行的ASSERT语句的数量
//用例里面实际执行的ASSERT语句的成功数量
//用例里面实际执行的ASSERT语句的失败数量
//用例里面实际执行的ASSERT语句的成功数量所占的百分比

//用例里面实际执行的ASSERT语句的失败信息

//是否因为ASSERT失败而跳出测试用例
//测试用例是否因为其他的异常而跳出

//执行测试用例捕获的非ASSERT失败弹出的其他异常信息

// TODO
void execute_case(
    std::string_view case_name
)noexcept{
    neotest::Timer timer;
    timer.start();
    try{
        case_dict.get(case_name)();
    }catch(neotest::RuntimeAssertFailedException const& ){
    }catch(std::exception const& ){
    }catch(char const* ){
    }catch(std::string_view ){
    }catch(std::string const& ){
    }catch(...){
    }
    timer.stop();
}
