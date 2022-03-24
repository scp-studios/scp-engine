#ifndef F6F1ECD5_2AD0_48D4_A336_1734A4EB8215
#define F6F1ECD5_2AD0_48D4_A336_1734A4EB8215

#include <cstdint>

// We have to include the event header because we are inhereting from the event
// class
#include <scp/scp.hpp>
#include <scp/event.hpp>
#include <scp/event-type.hpp>

namespace scp
{
    enum class key_t;
}

namespace scp::events
{
    // A single key event. Contains all the information required.
    struct SCPEXP key_t: public event_t
    {
        // The keycode of the key that was pressed down.
        scp::key_t key_code;
        
        // What type of key event is it.
        enum class key_type_t
        {
            PRESS, RELEASE, REPEAT
        };
        
        // Is it a press, release, or a repeat.
        key_type_t type;
        
        event_type_t get_type() const override { return event_type_t::KEY; }
    };
}

#endif /* F6F1ECD5_2AD0_48D4_A336_1734A4EB8215 */
