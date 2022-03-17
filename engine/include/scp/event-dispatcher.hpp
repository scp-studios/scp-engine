#ifndef CDC84E6A_90BB_4162_99DE_54E74478F92A
#define CDC84E6A_90BB_4162_99DE_54E74478F92A

#include <functional>
#include <scp/scp.hpp>

namespace scp
{
    // Forward declarations.
    class event_t;
    
    // No explanantions needed.
    using event_handler_t = std::function<void(const event_t& p_event)>;
    
    // A simple event dispatcher for dispatching events. It abstracts the deta-
    // ils of dispatching events away.
    class SCPEXP event_dispatcher_t
    {
    public:
        // Constructor.
        event_dispatcher_t(event_handler_t handler): m_handler(handler) {}
        
        // Dispatch an event.
        void dispatch(const event_t& event) const { m_handler(event); }
    private:
        // The function that is going to handle all the events.
        event_handler_t m_handler;
    };
}

#endif /* CDC84E6A_90BB_4162_99DE_54E74478F92A */
