#ifndef E04AC773_4DE8_4578_8FA8_2B63BFBFB73F
#define E04AC773_4DE8_4578_8FA8_2B63BFBFB73F

#include <SCP/pch.hpp>
#include <SCP/Events/Event.hpp>
#include <SCP/Layer.hpp>

namespace SCP
{
    // A singleton class representing a queue of events
    class EventQueue
    {
    public:
        // Obtain the instance of this class
        static EventQueue& getInstance();
        
        // Add an event to the queue
        void add(std::shared_ptr<Events::Event> event) { m_queue.push(event); }
        
        // Dispatch the event queue to a layer
        void dispatch(Layer& layer);
    private:
        std::queue<std::shared_ptr<Events::Event>> m_queue;
    };
}

#endif /* E04AC773_4DE8_4578_8FA8_2B63BFBFB73F */
