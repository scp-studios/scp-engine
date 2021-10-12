#ifndef AB48015C_C5C2_4B94_8163_687FE7BAB503
#define AB48015C_C5C2_4B94_8163_687FE7BAB503

namespace SCP::Events
{
    enum class EventType
    {
        KEY, MOUSE_CLICK, MOUSE_POS
    };
    
    class Event
    {
    public:
        virtual EventType getType() = 0;
        
        virtual ~Event() {}
    };
    
    #define SCP_EVENT_TYPE(x) EventType getType() { return EventType::x; }
}

#endif /* AB48015C_C5C2_4B94_8163_687FE7BAB503 */
