#include "pch.hpp"

#include <scp/input.hpp>
#include <scp/event.hpp>
#include <scp/events/key.hpp>
#include <scp/events/mouse.hpp>

#include "input-layer.hpp"

using scp::input_layer_t;

input_layer_t::input_layer_t(input_t& p_input_object): m_input_object(p_input_object)
{
    
}

bool input_layer_t::on_event(const event_t& p_event)
{
    if (p_event.get_type() == event_type_t::KEY)
    {
        const auto& key_event = static_cast<const events::key_t&>(p_event);
        m_input_object.m_keys[key_event.key_code] = (key_event.type == events::key_t::key_type_t::PRESS);
    }
    else if (p_event.get_type() == event_type_t::MOUSE_BUTTON)
    {
        const auto& mouse_button_event = static_cast<const events::mouse_button_t&>(p_event);
        m_input_object.m_mouse_buttons[mouse_button_event.mouse_code] = mouse_button_event.is_button_down;
    }
    else if (p_event.get_type() == event_type_t::MOUSE_POSITION)
    {
        const auto& mouse_position_event = static_cast<const events::mouse_position&>(p_event);
        m_input_object.m_mouse_x = mouse_position_event.x;
        m_input_object.m_mouse_y = mouse_position_event.y;
    }
    else if (p_event.get_type() == event_type_t::SCROLL)
    {
        const auto& scroll_event = static_cast<const events::scroll_t&>(p_event);
        m_input_object.m_vertical_scroll = scroll_event.y;
        m_input_object.m_horizontal_scroll = scroll_event.x;
    }
    
    return true;
}

input_layer_t::~input_layer_t()
{
    
}