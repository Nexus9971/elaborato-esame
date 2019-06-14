cmake_minimum_required(VERSION 3.14)

add_subdirectory(./lib/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES runAllTests.cpp TestDate.cpp TestTransaction.cpp TestAccount.cpp)
add_executable(runTestDate ${TEST_SOURCE_FILES})
target_link_libraries(runTestDate gtest gtest_main core)