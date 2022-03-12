#include <scp/window.hpp>

using scp::window_t;

window_t::window_t(int32_t width, int32_t height, std::string_view title, bool fullscreen)
{
	// Placeholder for now. We will add more later on.
	m_implementation = nullptr;
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