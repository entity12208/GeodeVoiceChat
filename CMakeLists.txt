cmake_minimum_required(VERSION 3.10)

project(VoiceChat VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(voicechat
    src/main.cpp
    src/voicechatmod.cpp
    lib/voicechatlib.cpp
)

target_include_directories(voicechat PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
    "${PROJECT_SOURCE_DIR}/lib"
)
