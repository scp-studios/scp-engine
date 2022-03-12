#include "../src/pch.hpp"

#include "window.hpp"

using scp::platform::windows::window_t;

// To keep track of whether the window class is already registered.
static bool is_window_class_already_registered = false;

// The name of the window class (for the Windows API, of course).
static LPCWSTR WINDOW_CLASS_NAME = L"scp::platform::windows::window_t";

// The global window procedure, used by almost all of the windows.
LRESULT window_t::global_window_procedure(HWND p_window, UINT p_message, WPARAM p_wide_parameter, LPARAM p_long_parameter)
{
	window_t* window;

	if (p_message == WM_NCCREATE)
	{
		CREATESTRUCT* create_struct = (CREATESTRUCT*)p_long_parameter;
		window = (window_t*)create_struct->lpCreateParams;
		SetWindowLongPtrW(p_window, GWLP_USERDATA, (LONG_PTR)window);
	}
	else
	{
		window = (window_t*)GetWindowLongPtr(p_window, GWLP_USERDATA);
	}

	if (window)
	{
		return window->window_procedure(p_message, p_wide_parameter, p_long_parameter);
	}
	else
	{
		return DefWindowProc(p_window, p_message, p_wide_parameter, p_long_parameter);
	}
}

window_t::window_t(int32_t p_width, int32_t p_height, std::string_view p_title, bool p_fullscreen)
{
	m_is_open = true;

	if (!is_window_class_already_registered)
	{
		WNDCLASSW window_class = {};
		window_class.hInstance = GetModuleHandleW(nullptr);
		window_class.lpszClassName = WINDOW_CLASS_NAME;
		window_class.lpfnWndProc = global_window_procedure;
		window_class.style = CS_OWNDC;
		
		RegisterClassW(&window_class);

		is_window_class_already_registered = true;
	}

	// Convert the title into a Unicode string.
	PWSTR title = nullptr;
	mbstowcs(title, p_title.data(), p_title.size());

	m_handle = CreateWindowExW(0, WINDOW_CLASS_NAME, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, p_width, p_height, nullptr, nullptr, GetModuleHandleW(nullptr), this);

	if (!m_handle)
	{
		std::cerr << "[ERROR]: Failed to create the window " << p_title << std::endl;
		return;
	}
}

bool window_t::is_open_impl() const
{
	return m_is_open;
}

void window_t::show_impl() const
{
	ShowWindow(m_handle, SW_SHOW);
}

void window_t::update_impl() const
{
	// Polls the event.
	MSG message = {};
	GetMessageW(&message, m_handle, 0, 0);

	TranslateMessage(&message);
	DispatchMessageW(&message);
}

window_t::~window_t()
{
	DestroyWindow(m_handle);
}

LRESULT window_t::window_procedure(UINT p_message, WPARAM p_wide_parameter, LPARAM p_long_parameter)
{
	switch (p_message)
	{
	case WM_CLOSE:
		m_is_open = false;
		return 0;
	default:
		return DefWindowProcW(m_handle, p_message, p_wide_parameter, p_long_parameter);
	}
}