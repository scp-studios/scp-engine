#ifndef AD554A3A_C5A6_48B6_8650_8CDAD2F67571
#define AD554A3A_C5A6_48B6_8650_8CDAD2F67571

namespace SCP::Events
{
    class MouseClickEvent
    {
    public:
        MouseClickEvent(int button): m_button(button) {}
        
        int getButton() { return m_button; }
        
    private:
        int m_button;
    };
}

#endif /* AD554A3A_C5A6_48B6_8650_8CDAD2F67571 */
