#include"main.h"
#include"neotest/neotest.h"

int main(int argc,char* argv[]){
    neotest::Timer t;
    t.start();
    std::cout<<"hello world!\n";
    t.stop();
    std::cout<<t.delta_string()<<'\n';
    return 0;
}
