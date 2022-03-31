target_sources(
    scp-engine PRIVATE
    
    dummy-layer.hpp
    engine.cpp
    engine.hpp
    game-launcher.cpp
    layer-stack.cpp
    pch.hpp
    scene-layer.cpp
    scene-layer.hpp
    scene.cpp
    window.cpp
    pch.hpp
)

target_precompile_headers(scp-engine PRIVATE pch.hpp)

add_subdirectory(platform)