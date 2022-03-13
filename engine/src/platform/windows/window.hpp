#pragma once

// This is a simple implementation of the window class for the Microsoft Windo-
// ws operating system. It is very simple for now, but we will extend it's beh-
// aviour later.

typedef HWND;
typedef UINT;
typedef WPARAM;
typedef LPARAM;

#include <scp/window.hpp>
#include <unordered_map>

namespace scp::platform::windows
{
	class window_t: public scp::window_t
	{
	public:
		window_t() = default;

		// Constructor with a few parameters
		window_t(int32_t width, int32_t height, std::string_view title, bool fullscreen);

		// You shouldn't need to copy windows during the program execution.
		window_t(window_t&) = delete;
		window_t& operator=(window_t&) = delete;

		// Returns whether or not the window is open.
		bool is_open_impl() const override;

		// Show the window.
		void show_impl() const override;

		// Updates the window (here, it just polls the events.)
		void update_impl() const override;

		// Destructor
		virtual ~window_t();
	private:
		// The actual window handle.
		HWND m_handle;

		// Whether the window is open or not.
		bool m_is_open;

		// The map of all the window classes and their HWNDs. I have to use th-
		// is approach because using window long pointers aren't working for s-
		// ome reasons.
		static std::unordered_map<HWND, window_t*> window_map;

		// The global window procedure
		static LRESULT global_window_procedure(HWND p_window, UINT p_message, WPARAM p_wide_parameter, LPARAM p_long_parameter);

		// The window procedure, which is per-window.
		LRESULT window_procedure(UINT message, WPARAM wide_parameter, LPARAM long_parameter);
	};
}