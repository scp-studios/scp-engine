#ifndef D8A2BB7E_E15A_4875_94EF_46E2EAF01B62
#define D8A2BB7E_E15A_4875_94EF_46E2EAF01B62

namespace scp
{
    // An enumeration that is used to identify the different types of events. 
    // We will add more events later on.
    enum class event_type_t
    {
        KEY = 0,
        MOUSE_POSITION,
        MOUSE_BUTTON,
        SCROLL 
    };
}

#endif /* D8A2BB7E_E15A_4875_94EF_46E2EAF01B62 */
