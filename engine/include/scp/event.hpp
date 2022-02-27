#ifndef EF09A24D_9E79_48B7_BBFE_AED0D7199449
#define EF09A24D_9E79_48B7_BBFE_AED0D7199449

namespace scp
{
    // A generic event class. It is used within the event system. Every event 
    // type that can be dispatched must inherit this class in order for them to
    // work.
    class event_t
    {
    public:
        // C++ will automatically insert a default constructor and all other c-
        // onstructors.
        
        // Returns the type of the event. Used within the event dispatcher. Cu-
        // rrently, we use an uint32_t to identify events, so that it's easier 
        // to add more events. However, we may add an enumeration later on.
        virtual uint32_t get_type() = 0;
    };
}

#endif /* EF09A24D_9E79_48B7_BBFE_AED0D7199449 */
