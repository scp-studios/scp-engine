#include <scp/game-launcher.hpp>
#include <scp/launch-configuration.hpp>
#include <scp/scene.hpp>
#include <scp/layer-stack.hpp>
#include <scp/layer.hpp>
#include <iostream>

class example_layer: public scp::layer_t
{
public:
    void update(double p_delta_time) override
    {
        std::cout << "Updated!" << std::endl;
    }
    
    ~example_layer()
    {
        
    }
};

int old_main()
{
    scp::layer_stack_t layer_stack;
    
    layer_stack.push_layer<example_layer>();
    
    layer_stack.update(15);
    layer_stack.render();
    
    return 0;
}

int main()
{
    scp::scene_t* starting_scene = new scp::scene_t();
    
    scp::launch_configuration_t launch_configuration = {
        *starting_scene
    };
    
    return scp::game_launcher::launch_game(launch_configuration);
}