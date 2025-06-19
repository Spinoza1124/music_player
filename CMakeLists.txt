# CMake最低版本要求
cmake_minimum_required(VERSION 3.16)

# 项目名称和版本
project(music_player VERSION 1.0)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 自动处理Qt的MOC, UIC, RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 查找需要的Qt6包
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Multimedia)

# ===================================================================
# === 修正部分：使用 PkgConfig 来查找 TagLib ========================
# ===================================================================
# 1. 首先找到 pkg-config 工具本身
find_package(PkgConfig REQUIRED)

# 2. 使用 pkg-config 检查 "taglib" 包是否存在，并为我们创建一个名为 PkgConfig::TAGLIB 的目标
#    这个目标会自动包含头文件和库文件的所有信息。
pkg_check_modules(TAGLIB REQUIRED IMPORTED_TARGET taglib)
# ===================================================================

# 添加头文件搜索路径
include_directories(include)

# 添加可执行文件及其源文件
add_executable(music_player
  src/main.cpp
  src/MainWindow.cpp
  # 如果你已经创建了 AudioEngine.cpp, 也要把它加进来
  # src/AudioEngine.cpp 
)

# 链接所有需要的库到我们的程序
target_link_libraries(music_player
  PRIVATE
  Qt6::Core
  Qt6::Gui
  Qt6::Widgets
  Qt6::Multimedia
  # 这里不再使用 TagLib::Tag，而是使用上面 PkgConfig 找到的目标
  PkgConfig::TAGLIB
)