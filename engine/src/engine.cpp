#include "pch.hpp"

#include <scp/scene.hpp>
#include <scp/event.hpp>

#include "engine.hpp"

using scp::engine_t;

// There are some events that we might wanted to handle directly before or ins-
// tead of sending to the scene, so I added this middle function for those pur-
// poses.
static void handle_event(const scp::event_t& p_event)
{
    scp::scene_t::send_event_to_active(p_event);
}

engine_t::engine_t(const launch_configuration_t& p_launch_configuration):
    m_event_dispatcher(handle_event),
    // The dimensions are hard-coded for now, but I will make them flexible la-
    // ter.
    m_window(1280, 720, "SCP Engine Window", m_event_dispatcher, false)
{
    
}

void engine_t::update()
{
    scp::scene_t::update_active(0);
    scp::scene_t::render_active();
    m_window.update();
}

bool engine_t::is_running()
{
    return m_window.is_open();
}