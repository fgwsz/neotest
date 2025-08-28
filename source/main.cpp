#include"main.h"

#include"neotest/neotest.h"

NEOTEST_CASE("Hello"){
    NEOTEST_RUNTIME_CHECK_EQ(0,0-3)<<"[msg]: "<<int{1};
    NEOTEST_RUNTIME_CHECK_EQ(1,1-3)<<"msg 2";
    NEOTEST_RUNTIME_CHECK_EQ(2,2-3)<<"msg 3";
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2)<<"runtime assert failed!";
}
NEOTEST_CASE("world!"){
    NEOTEST_RUNTIME_CHECK_EQ(1+1,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+2,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+4,5);
    NEOTEST_SKIP("This is info.")<<"This is msg!";
}
int main(int argc,char* argv[]){
    auto ei_1=neotest::execute_case("Hello");
    std::cout<<neotest::value_to_json(ei_1)<<'\n';

    auto ei_2=neotest::execute_case("world!");
    std::cout<<neotest::value_to_json(ei_2)<<'\n';
    return 0;
}
