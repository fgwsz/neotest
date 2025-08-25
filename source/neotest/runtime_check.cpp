#include"runtime_check.h"

void runtime_check_failed(
    std::string_view file
    ,std::string_view line
    ,std::string_view info
)noexcept;

void runtime_check(
    neotest::condition_info const& ci
)noexcept{
    runtime_check_count_increment();
    if(ci.condition==false){
        runtime_check_failed_count_increment();
        runtime_check_failed(ci.file,ci.line_str,ci.info);
    }else{
        runtime_check_passed_count_increment();
    }
}

void runtime_check_operator(
    neotest::condition_info const& ci
)noexcept{

static void runtime_check_count_reset(void)noexcept;
static void runtime_check_passed_count_reset(void)noexcept;
static void runtime_check_failed_count_reset(void)noexcept;
static void runtime_check_count_increment(void)noexcept;
static void runtime_check_passed_count_increment(void)noexcept;
static void runtime_check_failed_count_increment(void)noexcept;
static std::size_t get_runtime_check_count(void)noexcept;
static std::size_t get_runtime_check_passed_count(void)noexcept;
static std::size_t get_runtime_check_failed_count(void)noexcept;

//public
#define TEST_CHECK_OP(operator__,lhs__,rhs__) do{                            \
    test::detail::check_count_incement();                                  \
    if(!((lhs__)operator__(rhs__))){                                         \
        test::detail::check_failed_count_increment();                      \
        test::detail::check_failed(                                        \
            __FILE__                                                         \
            ,TEST_STR(__LINE__)                                              \
            ,(std::ostringstream{}<<(lhs__)<<" "#operator__" "<<(rhs__))   \
                .str()                                                       \
        );                                                                   \
    }else{                                                                   \
        test::detail::check_passed_count_increment();                      \
    }                                                                        \
}while(0)                                                                    \
//
//public
#define TEST_CHECK_EQ(lhs__,rhs__) TEST_CHECK_OP(==,lhs__,rhs__)
//public
#define TEST_CHECK_NE(lhs__,rhs__) TEST_CHECK_OP(!=,lhs__,rhs__)
//public
#define TEST_CHECK_GT(lhs__,rhs__) TEST_CHECK_OP(>,lhs__,rhs__)
//public
#define TEST_CHECK_GE(lhs__,rhs__) TEST_CHECK_OP(>=,lhs__,rhs__)
//public
#define TEST_CHECK_LT(lhs__,rhs__) TEST_CHECK_OP(<,lhs__,rhs__)
//public
#define TEST_CHECK_LE(lhs__,rhs__) TEST_CHECK_OP(<=,lhs__,rhs__)
//public
#define TEST_CHECK_AND(lhs__,rhs__) TEST_CHECK_OP(&&,lhs__,rhs__)
//public
#define TEST_CHECK_OR(lhs__,rhs__) TEST_CHECK_OP(||,lhs__,rhs__)
//public
#define TEST_CHECK_NOT(...) TEST_CHECK(!(__VA_ARGS__))

