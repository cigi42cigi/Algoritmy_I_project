cmake_minimum_required(VERSION 3.12)
project(MergedListProject)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wno-unused-result -Werror=uninitialized -Werror=return-type -Werror=vla")

add_executable(MergedListProject main.cpp List.cpp AllLists.cpp)


