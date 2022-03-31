#include <scp/game-launcher.hpp>
#include <scp/launch-configuration.hpp>
#include <scp/scene.hpp>

int main()
{
    scp::scene_t* starting_scene = new scp::scene_t();
    
    scp::launch_configuration_t launch_configuration = {
        *starting_scene
    };
    
    return scp::game_launcher::launch_game(launch_configuration);
}