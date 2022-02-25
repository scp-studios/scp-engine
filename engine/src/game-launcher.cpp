#include <scp/launch-configuration.hpp>
#include <scp/game-launcher.hpp>
#include <iostream>
#include <scp/fatal-error.hpp>
#include <cstdlib>

// Runs the game with the main loop and all that stuff.
static void run()
{
    // Currently just an infinite loop to get everything setted up.
    while (true)
    {
        
    }
}

// System specific ways of handling fatal errors. For now, just output it to t-
// he terminal.
static void handle_fatal_error(const scp::fatal_error_t& p_error)
{
    std::cerr << "[FATAL ERROR]: " << p_error.m_what << "\n";
}

int scp::game_launcher::launch_game(const scp::launch_configuration_t& p_launch_configuration)
{
    // The launch game functions handles all fatal errors
    try
    {
        run();
    }
    catch(const fatal_error_t& e)
    {
        handle_fatal_error(e);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}