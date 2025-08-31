#ifndef NEOTEST_MACRO_H

#define NEOTEST_STRINGIFY(...) #__VA_ARGS__

#define NEOTEST_TO_STRING(...) NEOTEST_STRINGIFY(__VA_ARGS__)

#define NEOTEST_CONCAT_IMPL(lhs__,...) lhs__##__VA_ARGS__

#define NEOTEST_CONCAT(lhs__,...) NEOTEST_CONCAT_IMPL(lhs__,__VA_ARGS__)

#ifdef __COUNTER__
#   define NEOTEST_UNIQUE_VAR_NAME(...) \
        NEOTEST_CONCAT(__VA_ARGS__,__COUNTER__)
#else
#   define NEOTEST_UNIQUE_VAR_NAME(...) \
        NEOTEST_CONCAT(__VA_ARGS__,__LINE__)
#endif

#endif//NEOTEST_MACRO_H
