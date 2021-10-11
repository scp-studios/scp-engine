#ifndef CE871BC7_0B25_4345_BB8D_B00CEBB63A9F
#define CE871BC7_0B25_4345_BB8D_B00CEBB63A9F

namespace SCP::Events
{
    class MousePosEvent
    {
    public:
        MousePosEvent(double x, double y): m_x(x), m_y(y) {}
        
        int getX() { return m_x; }
        
        int getY() { return m_y; }
        
    private:
        double m_x;
        double m_y;
    }
}

#endif /* CE871BC7_0B25_4345_BB8D_B00CEBB63A9F */
