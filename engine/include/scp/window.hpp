#pragma once

// A simple window class. It has no backends, which are supposed to be impleme-
// nted by the system specific classes. It's job is to create a simple window 
// and that's kind of it. It also has basic functions to managing a window.

#include <scp/scp.hpp>

#include <string_view>
#include <memory>

namespace scp
{
	class event_dispatcher_t;
	
	class SCPEXP window_t
	{
	public:
		// Default constructor that does nothing.
		window_t() = default;

		// Constructs a window from basic parameters.
		window_t(int32_t width, int32_t height, std::string_view title, event_dispatcher_t& event_dispatcher, bool fullscreen);

		// Removed the copy constructor and assignment operators to prevent pr-
		// oblems in the future.
		window_t(window_t&) = delete;
		window_t& operator=(window_t&) = delete;

		// Returns whether or not the window is open.
		bool is_open() const;

		// Show the window, as it's typically hidden by default.
		void show() const;
		
		// Change the window in and out of fullscreen mode.
		void set_fullscreen(bool value);

		// Update the window (basic operations such as swap buffers and event polling).
		void update();

		// Returns the backend handle of the window.
		window_t& get_implementation() const;

		// No comments needed here.
		virtual ~window_t();
	private:
		// The actual window object with the implementations.
		std::unique_ptr<window_t> m_implementation;

		// The implementation functions.
		virtual bool is_open_impl() const { return false;  }
		virtual void show_impl() const {}
		virtual void set_fullscreen_impl(bool value) {}
		virtual void update_impl() {}
	};
}