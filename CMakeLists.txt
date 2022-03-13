cmake_minimum_required(VERSION 3.13)

project("SCP Engine")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
endif()

if (WIN32)
    add_compile_definitions(SCP_PLATFORM_WINDOWS)
elseif(UNIX AND NOT APPLE)
    add_compile_definitions(SCP_PLATFORM_LINUX)
endif()

# Use absolute paths because it makes things much easier. Of course, this is o-
# nly available on Clang.
if (CMAKE_CXX_COMPILER_ID MATCHES Clang)
    add_compile_options(-fdiagnostics-absolute-paths)
    add_link_options(-fdiagnostics-absolute-paths)
endif()

add_subdirectory(engine)
add_subdirectory(sandbox)