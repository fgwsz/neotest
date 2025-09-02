cmake_minimum_required(VERSION 3.0)

# 获取项目名称
get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${PROJECT_NAME} LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 包含头文件目录
include_directories(include)
include_directories(include/neotest)

# 设置源文件
file(GLOB NEOTEST_SOURCES "source/neotest/*.cpp")

# 创建静态库
add_library(${PROJECT_NAME}_static STATIC ${NEOTEST_SOURCES})
set_target_properties(${PROJECT_NAME}_static PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# 创建共享库
add_library(${PROJECT_NAME}_shared SHARED ${NEOTEST_SOURCES})
set_target_properties(${PROJECT_NAME}_shared PROPERTIES OUTPUT_NAME ${PROJECT_NAME})

# 设置安装规则
install(TARGETS ${PROJECT_NAME}_static ${PROJECT_NAME}_shared
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/neotest/ DESTINATION include
        FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")

# 平台特定设置
if(MSVC)
    add_compile_options(/utf-8)
endif()
