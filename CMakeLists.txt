cmake_minimum_required(VERSION 3.10.0)

project(Legio VERSION 0.1.0)

add_executable(${PROJECT_NAME} src/core/main.cpp)

add_subdirectory(src/MyLib)

#Include directories and link directories
target_include_directories(${PROJECT_NAME} PUBLIC src/MyLib)
target_link_directories(${PROJECT_NAME} PUBLIC src/MyLib/)

#Link libraries
target_link_libraries(${PROJECT_NAME} MyLib)

