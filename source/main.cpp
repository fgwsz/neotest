#include"main.h"
#include"neotest/neotest.h"

NEOTEST_CASE("Hello"){
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2);
}
NEOTEST_CASE("world!"){
}
int main(int argc,char* argv[]){
    neotest::Timer t;
    t.start();
    std::cout<<"hello world!\n";
    t.stop();
    std::cout<<t.delta_string()<<'\n';
    neotest::case_dict.get("Hello")();
    return 0;
}
