#ifndef D332365C_BB1D_455C_A8CD_8886E9AFE3FE
#define D332365C_BB1D_455C_A8CD_8886E9AFE3FE

// This is one of the first times I've included two classes within a single fi-
// le, since I usually split classes up into multiple files. I've done this be-
// cause both classes are rather short, and they are kind of related in one way
// or another, so why not include both?

#include <scp/scp.hpp>
#include <scp/event.hpp>
#include <scp/event-type.hpp>
#include <scp/mouse-button.hpp>

typedef int32_t;

namespace scp::events
{
    // No comments needed
    struct SCPEXP mouse_button_t: public event_t
    {
        // The mouse code
        scp::mouse_button_t mouse_code;
        
        // Is the mouse button pressed down?
        bool is_button_down;
        
        event_type_t get_type() const override { return event_type_t::MOUSE_BUTTON; }
    };
    
    // No comments needed
    struct SCPEXP mouse_position: public event_t
    {
        // Where is the mouse x and y position?
        uint32_t x;
        uint32_t y;
        
        // Note: We are using unsigned integers because the coordinates are ne-
        // ver negative.
        
        event_type_t get_type() const override { return event_type_t::MOUSE_POSITION; }
    };
    
    // No comments needed
    struct SCPEXP scroll_t: public event_t
    {
        // How much is the mouse scrolled on the x and y axis?
        double x;
        double y;
        
        event_type_t get_type() const override { return event_type_t::SCROLL; }
    };
}

#endif /* D332365C_BB1D_455C_A8CD_8886E9AFE3FE */
