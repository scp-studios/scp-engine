#include "pch.hpp"

#include <scp/scene.hpp>
#include <scp/event.hpp>
#include <scp/launch-configuration.hpp>

#include <functional>

#include "scene-layer.hpp"

#include "engine.hpp"

using scp::engine_t;

static void handle_events(const scp::event_t& p_event)
{
    
}

engine_t& engine_t::get_instance(const launch_configuration_t& launch_configuration)
{
    static engine_t instance(launch_configuration);
    return instance;
}

engine_t::engine_t(const launch_configuration_t& p_launch_configuration):
    m_event_dispatcher(::handle_events),
    // The dimensions are hard-coded for now, but I will make them flexible la-
    // ter.
    m_window(1280, 720, "SCP Engine Window", m_event_dispatcher, false)
{
    m_global_layer_stack.push_layer<scene_layer_t>();
}

void engine_t::update()
{
    // Zero for now because we don't have a clock functionality yet.
    m_global_layer_stack.update(0);
    m_global_layer_stack.render();
    
    m_window.update();
}

bool engine_t::is_running() const
{
    return m_window.is_open();
}

void engine_t::show_window() const
{
    m_window.show();
}

engine_t::~engine_t()
{
    
}