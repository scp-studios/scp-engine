#include <scp/window.hpp>

#ifdef SCP_PLATFORM_WINDOWS
#include "platform/windows/window.hpp"
#endif

using scp::window_t;

window_t::window_t(int32_t width, int32_t height, std::string_view title, bool fullscreen)
{
#ifdef SCP_PLATFORM_WINDOWS
	m_implementation = new platform::windows::window_t(width, height, title, fullscreen);
#else
	m_implementation = this;
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

void window_t::update()
{
	return m_implementation->update_impl();
}

window_t* window_t::get_implementation() const
{
	return m_implementation;
}

window_t::~window_t()
{

}