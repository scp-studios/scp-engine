# Include directory
find_path(
    GLFW_INCLUDE_DIR 
    NAMES GLFW/glfw3.h GLFW/glfw3native.h 
    PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/include
    DOC "The absolute path the include directory of GLFW."
)

# Library (which depends on system)
if (WIN32)
    if(MSVC)
        find_library(
            GLFW_LIBRARY
            NAMES glfw3.lib glfw3dll.lib
            PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/src/Debug
                  ${CMAKE_SOURCE_DIR}/deps/glfw/src/Release
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src/Debug
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src/Release
            DOC "The absolute path to the library of GLFW."
        )
    else()
        find_library(
            GLFW_LIBRARY
            NAMES libglfw3.a libglfw3dll.a
            PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/src
                  ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
            DOC "The absolute path to the library of GLFW."
        )
    endif()
elseif(UNIX AND NOT APPLE AND NOT ANDROID)
    find_library(
        GLFW_LIBRARY
        NAMES libglfw3.a libglfw.so.3
        PATHS /usr/lib/x86_64-linux-gnu
              ${CMAKE_SOURCE_DIR}/deps/glfw/src
              ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
        DOC "The absolute path to the library of GLFW."
    )
elseif(APPLE AND NOT IOS)
    # I have no experience with developing for macs, so I'm just guessing here.
    find_library(
        GLFW_LIBRARY
        NAMES libglfw3.a libglfw.dylib
        PATHS ${CMAKE_SOURCE_DIR}/deps/glfw/src
              ${CMAKE_SOURCE_DIR}/deps/glfw/build/src
        DOC "The absolute path to the library of GLFW."
    )
endif()

# Creating the imported target
if (GLFW_LIBRARY MATCHES ".a$" OR GLFW_LIBRARY MATCHES ".lib$")
    add_library(GLFW::GLFW STATIC IMPORTED)
    set_property(TARGET GLFW::GLFW PROPERTY IMPORTED_LOCATION ${GLFW_LIBRARY})
elseif(GLFW_LIBRARY MATCHES ".dll$" OR GLFW_LIBRARY MATCHES ".*.so" OR GLFW_LIBRARY MATCHES ".dylib$")
    add_library(GLFW::GLFW SHARED IMPORTED)
    set_property(TARGET GLFW::GLFW PROPERTY IMPORTED_LOCATION ${GLFW_LIBRARY})
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GLFW DEFAULT_MSG GLFW_LIBRARY GLFW_INCLUDE_DIR)