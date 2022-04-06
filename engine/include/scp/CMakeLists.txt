target_sources(
    scp-engine PRIVATE
    
    event-dispatcher.hpp
    event-type.hpp
    event.hpp
    fatal-error.hpp
    game-launcher.hpp
    input.hpp
    key.hpp
    launch-configuration.hpp
    layer.hpp
    layer-stack.hpp
    mouse-button.hpp
    scene.hpp
    scp.hpp
    window.hpp
)

add_subdirectory(events)