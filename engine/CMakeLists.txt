add_library(scp-engine)

target_include_directories(scp-engine PRIVATE include)

add_subdirectory(src)
add_subdirectory(include/scp)

if (WIN32 AND BUILD_SHARED_LIBS)
    target_compile_definitions(scp-engine PRIVATE SCP_ENGINE_BUILD_DLL)
endif()

if (UNIX AND NOT APPLE)
    find_package(X11)
    target_include_directories(scp-engine PRIVATE ${X11_INCLUDE_DIR})
    target_link_libraries(scp-engine PRIVATE ${X11_LIBRARIES})
endif()

# Source groups
file(GLOB AAAA include/scp/events/*.hpp)
source_group("Header Files\\Events" FILES ${AAAA})
source_group("Source Files" FILES src/pch.hpp)

# Windows specific source group.
if (WIN32)
    file(GLOB AAAB src/platform/windows/*.cpp)
    file(GLOB AAAC src/platform/windows/*.hpp)
    source_group("Source Files\\Windows-Specific Code" FILES ${AAAB} ${AAAC})
endif()