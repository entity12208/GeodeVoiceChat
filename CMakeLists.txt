cmake_minimum_required(VERSION 3.10)

project(VoiceChatMod)

set(CMAKE_CXX_STANDARD 17)

add_library(voicechat SHARED src/voicechatmod.cpp src/main.cpp)

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIRS})
target_link_libraries(voicechat ${CURL_LIBRARIES})
