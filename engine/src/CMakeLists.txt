target_sources(
    scp-engine PRIVATE
    
    game-launcher.cpp
    pch.hpp
)

target_precompile_headers(scp-engine PRIVATE pch.hpp)