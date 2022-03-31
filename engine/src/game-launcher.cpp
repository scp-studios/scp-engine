#include "pch.hpp"

#include <scp/launch-configuration.hpp>
#include <scp/game-launcher.hpp>
#include <scp/event-dispatcher.hpp>
#include <scp/fatal-error.hpp>
#include <scp/event.hpp>
#include <scp/events/key.hpp>
#include <scp/key.hpp>
#include <scp/mouse-button.hpp>
#include <scp/scene.hpp>

#include <scp/events/mouse.hpp>
#include <iostream>
#include <cstdlib>

#include "engine.hpp"

#include <scp/window.hpp>

// Runs the game with the main loop and all that stuff.
static void run(const scp::launch_configuration_t& p_launch_configuration)
{
    scp::engine_t& engine = scp::engine_t::get_instance(p_launch_configuration);
    
    engine.show_window();
    
    while (engine.is_running())
    {
        engine.update();
    }
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
        run(p_launch_configuration);
    }
    catch(const fatal_error_t& e)
    {
        handle_fatal_error(e);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}