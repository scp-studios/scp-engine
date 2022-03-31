#include "pch.hpp"

#include <scp/scene.hpp>
#include <scp/event.hpp>
#include <scp/launch-configuration.hpp>

#include <functional>

#include "scene-layer.hpp"

#include "engine.hpp"

using scp::engine_t;

void engine_t::init(const launch_configuration_t& p_launch_configuration)
{
    instance = new engine_t(p_launch_configuration);
}

engine_t& engine_t::get_instance()
{
    return *instance;
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

engine_t::engine_t(const launch_configuration_t& p_launch_configuration):
    m_event_dispatcher(handle_event),
    // The dimensions are hard-coded for now, but I will make them flexible la-
    // ter.
    m_window(1280, 720, "SCP Engine Window", m_event_dispatcher, false)
{
    m_global_layer_stack.push_layer<scene_layer_t>(&(p_launch_configuration.start_scene));
}

void engine_t::handle_event(const event_t& p_event)
{
    instance->m_global_layer_stack.on_event(p_event);
}

engine_t* engine_t::instance = nullptr;