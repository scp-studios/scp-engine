target_sources(
    "scp-engine" PRIVATE
    
    "AppLauncher.hpp"
    "Application.hpp"
)

target_precompile_headers("scp-engine" PRIVATE "pch.hpp")