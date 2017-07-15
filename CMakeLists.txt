cmake_minimum_required(VERSION 2.6.4)
project(datastructures)

set (CMAKE_CXX_STANDARD 11)
add_definitions(-g)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/googletest/include)

enable_testing()
add_subdirectory( include )
add_subdirectory( googletest )
add_subdirectory(tests)

# this sets the output dir to /bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/install)

