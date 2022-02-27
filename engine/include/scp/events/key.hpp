#ifndef F6F1ECD5_2AD0_48D4_A336_1734A4EB8215
#define F6F1ECD5_2AD0_48D4_A336_1734A4EB8215

typedef int32_t;

namespace scp::events
{
    // A single key event. Contains all the information required.
    struct key_t
    {
        // We are using GLFW keycodes for now, but that should change in the f-
        // uture.
        int32_t key_code;
        
        // What type of key event is it.
        enum class type_t
        {
            PRESS, RELEASE, REPEAT
        };
        
        // Is it a press, release, or a repeat.
        type_t type;
    };
}

#endif /* F6F1ECD5_2AD0_48D4_A336_1734A4EB8215 */
