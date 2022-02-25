#ifndef AE110287_7E2D_4C47_9DEE_BF7630C9BC82
#define AE110287_7E2D_4C47_9DEE_BF7630C9BC82

namespace scp
{
    // Forward declaration.
    struct launch_configuration_t;
    
    // A function for launching a game. It will take a series of options, but 
    // for now, it does not take any options.
    namespace game_launcher
    {
        int launch_game(const launch_configuration_t& launch_configuration);
    }
}

#endif /* AE110287_7E2D_4C47_9DEE_BF7630C9BC82 */
