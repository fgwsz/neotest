#include"main.h"

#include"neotest/neotest.h"

NEOTEST_CASE("test.Hello"){
    NEOTEST_RUNTIME_CHECK_EQ(0,0-3)<<"[msg]: "<<int{1};
    NEOTEST_RUNTIME_CHECK_EQ(1,1-3)<<"msg 2";
    NEOTEST_RUNTIME_CHECK_EQ(2,2-3)<<"msg 3";
    NEOTEST_RUNTIME_ASSERT_EQ(1+2,2)<<"runtime assert failed!";
}
NEOTEST_CASE("test.World"){
    NEOTEST_RUNTIME_CHECK_EQ(1+1,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+2,2);
    NEOTEST_RUNTIME_CHECK_EQ(1+4,5);
    NEOTEST_SKIP("This is info.")<<"This is msg!";
}
NEOTEST_GROUP("test group"){
    NEOTEST_GROUP_ELEMENT_CASE("test.Hello");
    NEOTEST_GROUP_ELEMENT_CASE("test.World");
    NEOTEST_GROUP_ELEMENT_CASE_REGEX(R"(^test\..*)");
}
int main(int argc,char* argv[]){
    auto ei_vec=::neotest::execute_group(::std::regex("^test .*"));
    ::std::cout<<::neotest::value_to_json(ei_vec)<<'\n';
    return 0;
}
