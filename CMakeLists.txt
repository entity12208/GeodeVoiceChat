cmake_minimum_required(VERSION 3.16)
project(GeodeVoiceChat)

set(CMAKE_CXX_STANDARD 17)

# Find CURL
find_package(CURL REQUIRED)

# Include Geode SDK
set(GEODE_SDK_PATH "geode-sdk")
include_directories(${GEODE_SDK_PATH}/include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(voicechat ${SOURCES})

# Link libraries
target_link_libraries(voicechat CURL::libcurl)
