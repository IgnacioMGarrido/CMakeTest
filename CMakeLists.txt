cmake_minimum_required(VERSION 3.10.0)

project(Legio VERSION 1.0)

#Version the project
configure_file(LegioConfig.h.in LegioConfig.h)

add_executable(${PROJECT_NAME} src/core/main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

add_subdirectory(src/MyLib)

#### DOWNLOAD ALL SUBMODULES #####
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule Update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please check out submodules.")
        endif()
    endif() 
endif()     

####Check all Submodules ######
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/vendor/glfw/CMakeLists.txt")
    message(FATAL_ERROR "The glfw submodule was not downloaded! GIT_SUBMODULE was turned off or failed")
endif()

add_subdirectory(vendor/glfw)

#Include directories
target_include_directories(${PROJECT_NAME} 
    PUBLIC src/MyLib
    PUBLIC vendor/glfw/include
)

#Link directories
target_link_directories(${PROJECT_NAME}
    PUBLIC src/MyLib
    PRIVATE vendor/glfw/src
)

#Link libraries
target_link_libraries(${PROJECT_NAME} MyLib glfw)

