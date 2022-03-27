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
	// This is a function that runs every frame that may not run on the same t-
	// hread as the render function. It is used to process things that may need
	// to be processed every frame.
}

void scene_t::handle_event(const event_t& p_event)
{
	// Placeholder. Nothing here so far, but what it will do is it will propag-
	// ate the event through the layer stack.
}

void scene_t::render()
{
	// This is the function that will be called to render the scene. It will a-
	// lways be called from the rendering thread whenever neccessary, though on
	// some APIs that aren't specifically tied to any specific threads such as 
	// Vulkan, this may not be called from that thread.
}

scene_t* scene_t::active_scene = nullptr;