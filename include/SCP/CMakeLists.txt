target_sources(
    "SCPEngine" PRIVATE
    
    "AppLauncher.hpp"
    "Application.hpp"
    "EngineStates.hpp"
    "EventQueue.hpp"
    "pch.hpp"
    "Scene.hpp"
)

target_precompile_headers("SCPEngine" PRIVATE "pch.hpp")

add_subdirectory("Events")