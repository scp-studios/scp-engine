cmake_minimum_required(VERSION 3.16)

project("SCP Engine")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

find_package("GLFW")

if (UNIX)
    set(CMAKE_EXECUTABLE_SUFFIX ".out")
endif()

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

include_directories("include" "${GLFW_INCLUDE_DIR}")

add_library("SCPEngine")
add_executable("sandbox")

add_subdirectory("src")
add_subdirectory("include")

target_link_libraries("sandbox" "SCPEngine")
target_link_libraries("SCPEngine" "${GLFW_LIBRARY}")