#ifndef E05C405F_C3EA_478D_ACED_FB9BABD38A85
#define E05C405F_C3EA_478D_ACED_FB9BABD38A85

namespace scp
{
    class scene_t;
    
    // A set of parameters for the game launcher as to how to run the game. 
    struct launch_configuration_t
    {
        // The starting scene.
        scene_t& start_scene;
    };
}

#endif /* E05C405F_C3EA_478D_ACED_FB9BABD38A85 */
