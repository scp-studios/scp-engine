#include <scp/input.hpp>

using scp::input_t;

bool input_t::is_key_down(key_t p_key_code) const
{
    try
    {
        bool result = m_keys.at(p_key_code);
        return result;
    }
    catch(const std::out_of_range& e)
    {
        // If the key does not exist, we assume that it is false.
        return false;
    }
}

bool input_t::is_mouse_button_down(mouse_button_t p_mouse_button) const
{
    try
    {
        bool result = m_mouse_buttons.at(p_mouse_button);
        return result;
    }
    catch(const std::out_of_range& e)
    {
        // If the mouse button does not exist, we assume that is false.
        return false;
    }
}

uint32_t input_t::get_mouse_x() const 
{
    return m_mouse_x;
}

uint32_t input_t::get_mouse_y() const
{
    return m_mouse_y;
}

double input_t::get_vertical_scroll() const
{
    return m_vertical_scroll;
}

double input_t::get_horizontal_scroll() const
{
    return m_horizontal_scroll;
}