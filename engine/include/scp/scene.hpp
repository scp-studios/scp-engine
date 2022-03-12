#pragma once

// A very basic scene class. In this engine, a scene is basically a certain gr-
// oup of entities that happens to show up around the same time. Basically, it
// is a scene in the old traditional sense. For now, the scene class is very s-
// imple, but it will have more things added to it later on.

#include <scp/scp.hpp>

namespace scp
{
	class SCPEXP scene_t
	{
	public:
		// Default constructor for now, but will add parameters later on.
		scene_t();

		// The scene class is in charge of switching scenes. Therefore, we have
		// the functions for updating and rendering the current scene. 

		// Set the active scene.
		static void set_active(scene_t* new_active);

		// Update the active scene.
		static void update_active(double delta_time);

		// Render the active scene.
		static void render_active();

		// Destructor. No explanations needed
		virtual ~scene_t();
	private:
		// Updates the scene. Private because you don't update a scene that is
		// not active.
		void update(double delta_time);

		// Renders the scene. Private because you don't render a scene that is 
		// not active.
		void render();

		// The currently active scene.
		static scene_t* active_scene;
	};
}