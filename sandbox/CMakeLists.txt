add_executable(sandbox)

target_include_directories(sandbox PRIVATE ${CMAKE_SOURCE_DIR}/engine/include)

target_link_libraries(sandbox scp-engine)

add_subdirectory(src)