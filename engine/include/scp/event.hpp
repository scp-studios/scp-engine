#ifndef EF09A24D_9E79_48B7_BBFE_AED0D7199449
#define EF09A24D_9E79_48B7_BBFE_AED0D7199449

#include <scp/scp.hpp>

#include <cstdint>

namespace scp
{
    enum class event_type_t;
    
    // A generic event class. It is used within the event system. Every event 
    // type that can be dispatched must inherit this class in order for them to
    // work.
    class SCPEXP event_t
    {
    public:
        // C++ will automatically insert a default constructor and all other c-
        // onstructors.
        
        // Returns the type of the event.
        virtual event_type_t get_type() const = 0;
    };
}

#endif /* EF09A24D_9E79_48B7_BBFE_AED0D7199449 */
