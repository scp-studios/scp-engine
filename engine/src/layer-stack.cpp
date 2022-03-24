#include "pch.hpp"

#include <scp/layer.hpp>
#include <scp/event.hpp>

#include <scp/layer-stack.hpp>

using scp::layer_stack_t;

void layer_stack_t::push_layer(layer_t* layer)
{
    m_layer_stack.push_back(layer);
}

void layer_stack_t::pop_back()
{
    m_layer_stack.pop_back();
}

void layer_stack_t::on_event(const event_t& event)
{
    for (std::vector<layer_t*>::iterator i = m_layer_stack.end(); i != m_layer_stack.begin(); i--)
    {
        (*i)->on_event(event);
    }
}

void layer_stack_t::update(double p_delta_time)
{
    for (auto layer: m_layer_stack)
    {
        layer->update(p_delta_time);
    }
}

void layer_stack_t::render()
{
    for (auto layer: m_layer_stack)
    {
        layer->render();
    }
}