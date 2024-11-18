cmake_minimum_required(VERSION 3.10)
project(BanGUI)

# 指定C语言编译器
set(CMAKE_C_COMPILER gcc)

# 设置源文件
file(GLOB_RECURSE SRC_FILES
    "./src/*.c"
    "./emulator/*.c"
    "./keyinput/*.c"
    "./components/base_func/*.c"
    "./components/BG_List/*.c"
    "./components/page/*.c"
)

# 生成可执行文件
add_executable(BanGUI ${SRC_FILES})

# 设置头文件目录
target_include_directories(BanGUI PUBLIC
    ./include
    ./emulator
    ./keyinput
    ./components/base_func
    ./components/BG_List
    ./components/page
)
# 查找 SDL2 库
find_package(SDL2 REQUIRED)

# 包含 SDL2 的头文件目录
include_directories(${SDL2_INCLUDE_DIRS})

# 链接所需的库
target_link_libraries(BanGUI ${SDL2_LIBRARIES} ev asound m)
