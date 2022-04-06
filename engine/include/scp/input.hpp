#ifndef C948057B_DD7D_4627_9597_B58DB02706EF
#define C948057B_DD7D_4627_9597_B58DB02706EF

#include <scp/scp.hpp>
#include "key.hpp"
#include "mouse-button.hpp"
#include <stdint.h>
#include <unordered_map>

namespace scp
{
    // A basic input polling class for, well, input polling. Allows you to ret-
    // rieve basic stuff about input such as which mouse buttons are down and  
    class input_t
    {
    public:
        // The input layer has to be a friend class because it needs to modify 
        // internal values.
        friend class input_layer_t;
        
        // Constructor. Takes no parameters.
        input_t() = default;
        
        // Is the key specified pressed down?
        bool is_key_down(key_t key_code) const;
        
        // Is the mouse button specified pressed down?
        bool is_mouse_button_down(mouse_button_t mouse_code) const;
        
        // Get the mouse x coordinate.
        uint32_t get_mouse_x() const;
        
        // Get the mouse y coordinate.
        uint32_t get_mouse_y() const;
        
        // Get the vertical mouse scroll value.
        double get_vertical_scroll() const;
        
        // Get the horizontal mouse scroll value.
        double get_horizontal_scroll() const;
        
    private:
        // The statuses of all the keys.
        std::unordered_map<key_t, bool> m_keys;
        
        // The status of all the mouse buttons.
        std::unordered_map<mouse_button_t, bool> m_mouse_buttons;
        
        // Mouse positon.
        uint32_t m_mouse_x;
        uint32_t m_mouse_y;
        
        // Mouse scroll.
        double m_vertical_scroll;
        double m_horizontal_scroll;
    };
}

#endif /* C948057B_DD7D_4627_9597_B58DB02706EF */
