target_sources(
    "SCPEngine" PRIVATE
    
    "AppLauncher.hpp"
    "Application.hpp"
)

target_precompile_headers("SCPEngine" PRIVATE "pch.hpp")