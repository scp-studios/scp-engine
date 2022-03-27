#include "pch.hpp"

#include <scp/event.hpp>
#include <scp/events/key.hpp>
#include <scp/events/mouse.hpp>

#include <scp/scene.hpp>

using scp::scene_t;

scene_t::scene_t()
{
	// Placeholder
}

void scene_t::set_active(scene_t* p_new_active)
{
	if (active_scene != nullptr)
	{
		delete active_scene;
	}

	active_scene = p_new_active;
	
	active_scene->on_active();
}

void scene_t::update_active(double p_delta_time)
{
	active_scene->update(p_delta_time);
}

void scene_t::send_event_to_active(const event_t& p_event)
{
	active_scene->handle_event(p_event);
}

void scene_t::render_active()
{
	active_scene->render();
}

scene_t::~scene_t()
{
	// Placeholder
}

void scene_t::on_active()
{
	// Placeholder for now. This function is called whenever the scene is set  
	// as the default scene.
}

void scene_t::update(double p_delta_time)
{
	m_layer_stack.update(p_delta_time);
}

void scene_t::handle_event(const event_t& p_event)
{
	m_layer_stack.on_event(p_event);
}

void scene_t::render()
{
	m_layer_stack.render();
}

scene_t* scene_t::active_scene = nullptr;