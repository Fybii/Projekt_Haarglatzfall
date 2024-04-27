# ReqNonFunc 3

cmake_minimum_required(VERSION 3.10)
project(JsonToBatch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# All C++ files we need:
set(SOURCES src/main.cpp src/jsonClass.cpp src/jsonFinder.cpp src/command.cpp src/CreateBatch.cpp)

# Add all source files here
add_executable(JsonToBatch ${SOURCES})

target_include_directories(JsonToBatch PRIVATE ${PROJECT_SOURCE_DIR}/header)
target_link_libraries(JsonToBatch jsoncpp)
# Configure additional settings here, e.g., compiler flags or libraries