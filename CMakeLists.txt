# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(VoiceChat VERSION 1.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(voicechat src/main.cpp lib/voicechatlib.cpp)

# Include directories
target_include_directories(voicechat PUBLIC "${PROJECT_BINARY_DIR}")
target_include_directories(voicechat PUBLIC "${PROJECT_SOURCE_DIR}/src")
target_include_directories(voicechat PUBLIC "${PROJECT_SOURCE_DIR}/lib")

# Link libraries (if any)
# target_link_libraries(voicechat <library>)
