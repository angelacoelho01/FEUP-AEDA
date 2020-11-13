cmake_minimum_required(VERSION 3.17)
project(aeda1718_cp02)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aeda1718_cp02 main.cpp Tests/Test.cpp Tests/Doctor.cpp Tests/Hospital.cpp)

target_link_libraries(aeda1718_cp02 gtest gtest_main)