target_sources(
    scp-engine PRIVATE
    
    game-launcher.cpp
    scene.cpp
    window.cpp
    pch.hpp
)

target_precompile_headers(scp-engine PRIVATE pch.hpp)