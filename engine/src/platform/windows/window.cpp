#include "../src/pch.hpp"

#include "window.hpp"

using scp::platform::windows::window_t;

// The name of the window class (for the Windows API, of course).
static const wchar_t* WINDOW_CLASS_NAME = L"scp::platform::windows::window_t";

std::unordered_map<HWND, window_t*> window_t::window_map;

static const wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

// The global window procedure, used by almost all of the windows.
LRESULT window_t::global_window_procedure(HWND p_window, UINT p_message, WPARAM p_wide_parameter, LPARAM p_long_parameter)
{
	if (window_map.find(p_window) != window_map.end())
	{
		return window_map.at(p_window)->window_procedure(p_message, p_wide_parameter, p_long_parameter);
	}
	else
	{
		return DefWindowProcW(p_window, p_message, p_wide_parameter, p_long_parameter);
	}
}

window_t::window_t(int32_t p_width, int32_t p_height, std::string_view p_title, bool p_fullscreen)
{
	m_is_open = true;

	WNDCLASSW window_class = {};
	window_class.hInstance = GetModuleHandleW(nullptr);
	window_class.lpszClassName = WINDOW_CLASS_NAME;
	window_class.lpfnWndProc = global_window_procedure;
	window_class.style = CS_OWNDC;
	window_class.hCursor = LoadCursorA(nullptr, IDC_ARROW);

	RegisterClassW(&window_class);

	wchar_t* title = new wchar_t[p_title.size() + 1];
	mbstowcs(title, p_title.data(), p_title.size() + 1);

	m_handle = CreateWindowExW(0, WINDOW_CLASS_NAME, title, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, p_width, p_height, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);

	if (!m_handle)
	{
		std::cerr << "[WIN32 ERROR " << GetLastError() << "]: Failed to create the window " << p_title << std::endl;
		m_is_open = false;
		return;
	}

	window_map.insert(std::pair(m_handle, this));

	delete[] title;
}

bool window_t::is_open_impl() const
{
	return m_is_open;
}

void window_t::show_impl() const
{
	ShowWindow(m_handle, SW_SHOWNORMAL);
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
	case WM_PAINT:
	{
		PAINTSTRUCT ps = {};
		BeginPaint(m_handle, &ps);
		EndPaint(m_handle, &ps);
		return 0;
	}
	default:
		return DefWindowProcW(m_handle, p_message, p_wide_parameter, p_long_parameter);
	}
}