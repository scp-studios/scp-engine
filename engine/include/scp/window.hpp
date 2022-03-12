#pragma once

// A simple window class. It has no backends, which are supposed to be impleme-
// nted by the system specific classes. It's job is to create a simple window 
// and that's kind of it. It also has basic functions to managing a window.

typedef int32_t;

#include <string_view>

namespace scp
{
	class window_t
	{
	public:
		// Default constructor that does nothing.
		window_t() = default;

		// Constructs a window from basic parameters.
		window_t(int32_t width, int32_t height, std::string_view title, bool fullscreen);

		// 
	};
}