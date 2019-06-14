cmake_minimum_required(VERSION 3.14)
project(ProgettoProgrammazione)

add_subdirectory(Test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Account.h Account.cpp Date.h Date.cpp Transaction.h Transaction.cpp)

add_executable(ProgettoProgrammazione main.cpp)

add_library(core ${SOURCE_FILES})

target_link_libraries(ProgettoProgrammazione core)