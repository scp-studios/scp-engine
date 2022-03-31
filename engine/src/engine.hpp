#ifndef B92AD3D5_3EA3_48BA_9D18_87B40DD5F51D
#define B92AD3D5_3EA3_48BA_9D18_87B40DD5F51D

// An internal class used to manage the engine as a whole. It handles everythi-
// ng from the global layer stack to the window itself.

#include <scp/window.hpp>
#include <scp/layer.hpp>
#include <scp/layer-stack.hpp>
#include <scp/event-dispatcher.hpp>

namespace scp
{
    struct launch_configuration_t;
    
    class engine_t
    {
    public:
        engine_t(const launch_configuration_t& launch_configuration);
        
        void update();
        
        // Is the game still running?
        bool is_running() const;
        
        // Show the window.
        void show_window() const;
        
        ~engine_t();
        
    private:
        // The function for handling events.
        void handle_events(const event_t& event);
        
        // The event dispatcher (for recieving events from the window)
        event_dispatcher_t m_event_dispatcher;
        
        // The main window of the engine.
        window_t m_window;
        
        // The outer layer stack.
        layer_stack_t m_global_layer_stack;
    };
}

#endif /* B92AD3D5_3EA3_48BA_9D18_87B40DD5F51D */
