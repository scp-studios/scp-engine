#ifndef A18A636F_5FA0_469F_A5E7_037B0AB229A8
#define A18A636F_5FA0_469F_A5E7_037B0AB229A8

namespace SCP::Events
{
    class KeyEvents
    {
    public:
        KeyEvents(int keyCode): m_keyCode(keyCode) {}
        
        // Get the keycode
        int getKeyCode() { return m_keyCode; }
        
    private:
        int m_keyCode;
    };
}

#endif /* A18A636F_5FA0_469F_A5E7_037B0AB229A8 */
