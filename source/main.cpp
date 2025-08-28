#include"main.h"

#include<format>//std::format

#include"neotest/neotest.h"
#include"neotest/execute_case_info_to_string.h"

NEOTEST_CASE("Hello"){
    NEOTEST_RUNTIME_CHECK_EQ(0,0-3)<<"[msg]: "<<int{1};
    NEOTEST_RUNTIME_CHECK_EQ(1,1-3)<<"msg 2";
    NEOTEST_RUNTIME_CHECK_EQ(2,2-3)<<"msg 3";
    //NEOTEST_SKIP("this is skip reason!")<<"[msg]: skip msg";
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2)<<"msg assert failed!";
}
NEOTEST_CASE("world!"){
    NEOTEST_RUNTIME_CHECK_EQ(1+2,2);
    //NEOTEST_RUNTIME_CHECK_EQ(1+1,3);<<"[message]:"<<int{100};
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
