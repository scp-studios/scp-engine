#include "pch.hpp"

#include <scp/scene.hpp>

#include "scene-layer.hpp"

using scp::scene_layer_t;

void scene_layer_t::update(double p_delta_time)
{
    scene_t::update_active(p_delta_time);
}

void scene_layer_t::render()
{
    scene_t::render_active();
}

void scene_layer_t::on_event(const event_t& p_event)
{
    scene_t::send_event_to_active(p_event);
}

scene_layer_t::~scene_layer_t()
{
    
}