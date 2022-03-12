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
}

void scene_t::update_active(double p_delta_time)
{
	active_scene->update(p_delta_time);
}

void scene_t::render_active()
{
	active_scene->render();
}

scene_t::~scene_t()
{
	// Placeholder
}

void scene_t::update(double p_delta_time)
{
	// This is a function that runs every frame that may not run on the same t-
	// hread as the render function. It is used to process things that may need
	// to be processed every frame.
}

void scene_t::render()
{
	// This is the function that will be called to render the scene. It will a-
	// lways be called from the rendering thread whenever neccessary, though on
	// some APIs that aren't specifically tied to any specific threads such as 
	// Vulkan, this may not be called from that thread.
}

scene_t* scene_t::active_scene = nullptr;