cmake_minimum_required(VERSION 3.17)
project(Cynamic)

add_subdirectory(src)
add_executable(Cynamic main.c)
target_link_libraries(Cynamic List)
