cmake_minimum_required(VERSION 3.12)

project(SimpleVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall")

#--- Include project files
file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} main.cpp ${sources}  ${headers})
