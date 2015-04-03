cmake_minimum_required(VERSION 3.1)
project(ballin_octo_shame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Yo.cc
    Yo.h)

add_library(ballin_octo_shame ${SOURCE_FILES})

enable_testing()

add_subdirectory(third_party/googletest)

include_directories(${gtest_SOURCE_DIR}/include)

add_executable(tests Yo_test.cc Yo.cc)
target_link_libraries(tests gtest_main)

add_test(NAME whatup COMMAND tests)
