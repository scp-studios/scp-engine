cmake_minimum_required(VERSION 3.16)

project("SCP Engine")

add_library("scp-engine")
add_executable("sandbox")

add_subdirectory("src")
add_subdirectory("include")