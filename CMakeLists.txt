# 设置最低的 CMake 版本要求
cmake_minimum_required(VERSION 3.15)

# 设置项目名称和版本
project(StackExample VERSION 1.0 LANGUAGES C)

# 启用 C11 标准
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 创建一个静态库 target，用于存储栈实现
add_library(stack_lib
    src/stack.c
    src/stack_array.c
    src/stack_linked.c
)

# 指定库的公共和私有头文件路径
target_include_directories(stack_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include # 公共接口（用户可见）
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/internal # 内部头文件（隐藏）
)

# 创建主程序 target
add_executable(StackExample src/main.c)

# 链接主程序和库
target_link_libraries(StackExample PRIVATE stack_lib)

# 输出路径设置（可选）
set_target_properties(StackExample PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    OUTPUT_NAME stack_example
)
