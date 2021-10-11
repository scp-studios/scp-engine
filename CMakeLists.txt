cmake_minimum_required(VERSION 3.16)

project("SCP Engine")

set(CMAKE_CXX_STANDARD 17)

if (UNIX)
    set(CMAKE_EXECUTABLE_SUFFIX ".out")
endif()

if (MSVC)
    add_compile_options("/W4")
else()
    add_compile_options("-Wall")
endif()

include_directories("include")

add_library("scp-engine")
add_executable("sandbox")

add_subdirectory("src")
add_subdirectory("include")

target_link_libraries("sandbox" "scp-engine")