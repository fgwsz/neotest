#include"main.h"
#include"neotest/neotest.h"
#include"neotest/case.h"

NEOTEST_CASE("Hello"){
}
NEOTEST_CASE("world!"){
}
int main(int argc,char* argv[]){
    neotest::Timer t;
    t.start();
    std::cout<<"hello world!\n";
    t.stop();
    std::cout<<t.delta_string()<<'\n';
    return 0;
}
