#include "pch.hpp"

#include <scp/launch-configuration.hpp>
#include <scp/game-launcher.hpp>
#include <iostream>
#include <scp/fatal-error.hpp>
#include <cstdlib>

#include <scp/window.hpp>

// Runs the game with the main loop and all that stuff.
static void run()
{
    scp::window_t window(1280, 720, "SCP Engine Sandbox", false);

    window.show();
    while (window.is_open())
    {
        window.update();
    }
    
    std::cout << "goodbye!" << std::endl;
}

// System specific ways of handling fatal errors.
static void handle_fatal_error(const scp::fatal_error_t& p_error)
{
#ifdef SCP_PLATFORM_WINDOWS
    wchar_t* error_message = nullptr;
    mbstowcs(error_message, p_error.m_what.data(), p_error.m_what.size());
    MessageBoxW(nullptr, error_message, L"FATAL ERROR", MB_ICONERROR | MB_OK);
#else
    std::cerr << "[FATAL ERROR]: " << p_error.m_what << std::endl;
#endif
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