#ifndef AD554A3A_C5A6_48B6_8650_8CDAD2F67571
#define AD554A3A_C5A6_48B6_8650_8CDAD2F67571

#include <SCP/Events/Event.hpp>

namespace SCP::Events
{
    class MouseClickEvent: public Event
    {
    public:
        MouseClickEvent(int button): m_button(button) {}
        
        int getButton() { return m_button; }
        
        SCP_EVENT_TYPE(MOUSE_CLICK)
        
    private:
        int m_button;
    };
}

#endif /* AD554A3A_C5A6_48B6_8650_8CDAD2F67571 */
