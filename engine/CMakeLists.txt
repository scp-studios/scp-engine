add_library(scp-engine)

target_include_directories(scp-engine PRIVATE include)

add_subdirectory(src)
add_subdirectory(include/scp)

if (WIN32 AND BUILD_SHARED_LIBS)
    target_compile_definitions(scp-engine PRIVATE SCP_ENGINE_BUILD_DLL)
endif()