target_sources(
    scp-engine PRIVATE
    
    event_type.hpp
    event.hpp
    fatal-error.hpp
    game-launcher.hpp
    launch-configuration.hpp
)

add_subdirectory(events)