add_executable(sandbox)

target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR}/engine/include)

add_subdirectory(src)