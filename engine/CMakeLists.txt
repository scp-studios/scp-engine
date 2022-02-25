add_library(scp-engine)

target_include_directories(scp-engine PRIVATE include)

add_subdirectory(src)
add_subdirectory(include/scp)