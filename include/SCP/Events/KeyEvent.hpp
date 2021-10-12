#ifndef A18A636F_5FA0_469F_A5E7_037B0AB229A8
#define A18A636F_5FA0_469F_A5E7_037B0AB229A8

#include <SCP/Events/Event.hpp>

namespace SCP::Events
{
    class KeyEvent: public Event
    {
    public:
        KeyEvent(int keyCode): m_keyCode(keyCode) {}
        
        // Get the keycode
        int getKeyCode() { return m_keyCode; }
        
        SCP_EVENT_TYPE(KEY)
        
    private:
        int m_keyCode;
    };
}

#endif /* A18A636F_5FA0_469F_A5E7_037B0AB229A8 */
