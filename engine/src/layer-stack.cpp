#include "pch.hpp"

#include <scp/layer.hpp>
#include <scp/event.hpp>

#include <scp/layer-stack.hpp>

using scp::layer_stack_t;

void layer_stack_t::pop_back()
{
    m_layer_stack.pop_back();
}

void layer_stack_t::on_event(const event_t& event)
{
    for (std::vector<std::unique_ptr<layer_t>>::iterator i = m_layer_stack.end() - 1; i >= m_layer_stack.begin(); i--)
    {
        if (!(*i)->on_event(event))
        {
            return;
        }
    }
}

void layer_stack_t::update(double p_delta_time)
{
    for (std::vector<std::unique_ptr<layer_t>>::iterator i = m_layer_stack.begin(); i != m_layer_stack.end(); i++)
    {
        (*i)->update(p_delta_time);
    }
}

void layer_stack_t::render()
{
    for (std::vector<std::unique_ptr<layer_t>>::iterator i = m_layer_stack.begin(); i != m_layer_stack.end(); i++)
    {
        (*i)->render();
    }
}