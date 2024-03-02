cmake_minimum_required(VERSION 3.10)
project(labф3)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SCR src/farray.hpp src/farray.cpp src/point.hpp src/point.cpp src/figure.hpp src/figure.cpp src/trapezoid.hpp src/trapezoid.cpp src/rhomb.hpp src/rhomb.cpp src/pentagon.hpp src/pentagon.cpp)

add_executable(laba3 main.cpp src/farray.hpp src/farray.cpp src/point.hpp src/point.cpp src/figure.hpp src/figure.cpp src/trapezoid.hpp src/trapezoid.cpp src/rhomb.hpp src/rhomb.cpp src/pentagon.hpp src/pentagon.cpp)

enable_testing()
add_executable(tests tests.cpp src/farray.hpp src/farray.cpp src/point.hpp src/point.cpp src/figure.hpp src/figure.cpp src/trapezoid.hpp src/trapezoid.cpp src/rhomb.hpp src/rhomb.cpp src/pentagon.hpp src/pentagon.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})

add_test(NAME BASIC COMMAND tests)