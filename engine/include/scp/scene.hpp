#pragma once

// A very basic scene class. In this engine, a scene is basically a certain gr-
// oup of entities that happens to show up around the same time. Basically, it
// is a scene in the old traditional sense. For now, the scene class is very s-
// imple, but it will have more things added to it later on.

#include <scp/scp.hpp>

#include <scp/layer-stack.hpp>

namespace scp
{
	class event_t;
	
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
		
		// Pass an event to the active scene.
		static void send_event_to_active(const event_t& event);

		// Render the active scene.
		static void render_active();

		// Destructor. No explanations needed
		virtual ~scene_t();
	private:
		// Called when the scene is set to the active scene.
		void on_active();
		
		// Updates the scene. Private because you don't update a scene that is
		// not active.
		void update(double delta_time);
		
		// Handle events.
		void handle_event(const event_t& event);

		// Renders the scene. Private because you don't render a scene that is 
		// not active.
		void render();

		// The currently active scene.
		static scene_t* active_scene;
		
		// The layer stack that contains all of the layers.
		layer_stack_t m_layer_stack;
	};
}