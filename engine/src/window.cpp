#include "pch.hpp"

#include <scp/event-dispatcher.hpp>

#include <scp/window.hpp>

#ifdef SCP_PLATFORM_WINDOWS
#include "platform/windows/window.hpp"
#else
	#ifdef SCP_PLATFORM_LINUX
		#include "platform/linux/x11-window.hpp"
	#endif
#endif

using scp::window_t;

window_t::window_t(int32_t width, int32_t height, std::string_view title, event_dispatcher_t& event_dispatcher, bool fullscreen)
{
#ifdef SCP_PLATFORM_WINDOWS
	m_implementation = new platform::windows::window_t(width, height, title, event_dispatcher, fullscreen);
#else
	#ifdef SCP_PLATFORM_LINUX
		m_implementation = std::make_unique<scp::platform::linux_n::x11_window_t>(width, height, title, event_dispatcher, fullscreen);
	#endif
#endif
}

bool window_t::is_open() const
{
	return m_implementation->is_open_impl();
}

void window_t::show() const
{
	return m_implementation->show_impl();
}

void window_t::set_fullscreen(bool value)
{
	m_implementation->set_fullscreen_impl(value);
}

void window_t::update()
{
	return m_implementation->update_impl();
}

window_t& window_t::get_implementation() const
{
	return *m_implementation;
}

window_t::~window_t()
{

}