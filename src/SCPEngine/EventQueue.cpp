#include <SCP/EventQueue.hpp>

using SCP::EventQueue;

EventQueue& EventQueue::getInstance()
{
    static EventQueue eventQueue;
    return eventQueue;
}




void EventQueue::dispatch(Layer& layer)
{
    for (uint16_t i = 0; i < m_queue.size(); i++)
    {
        Events::Event& event = *m_queue.front();
        
        switch (event.getType())
        {
        case Events::EventType::MOUSE_POS:
            if (layer.onMousePosEvent(static_cast<Events::MousePosEvent&>(event)))
            {
                m_queue.pop();
            }
            break;
        case Events::EventType::KEY:
            if (layer.onKeyEvent(static_cast<Events::KeyEvent&>(event)))
            {
                m_queue.pop();
            }
            break;
        case Events::EventType::MOUSE_CLICK:
            if (layer.onMouseClickEvent(static_cast<Events::MouseClickEvent&>(event)))
            {
                m_queue.pop();
            }
            break;
        }
    }
}