cmake_minimum_required(VERSION 3.20)

project(esercitazione6)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Target per il main.cpp
add_executable(main main.cpp)

# Target per testing.cpp
add_executable(testing testing.cpp)

add_test(NAME test_grafi COMMAND test_grafi)
enable_testing()
