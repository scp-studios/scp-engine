#ifndef BF230894_3A15_4E2F_B695_7A65ABE76764
#define BF230894_3A15_4E2F_B695_7A65ABE76764

#include <scp/scp.hpp>
#include <vector>

// A simple, multipurposed layer stack. It's for the layer system. It's very s-
// imple for now.
//
//
// A little bit of background information on what I'm planning to do: there wi-
// ll be two layer stacks within the engine: the global layer stack, managed by
// the application itself, and the layer stacks within each scene.

namespace scp
{
    class layer_t;
    class event_t;
    
    class SCPEXP layer_stack_t
    {
    public:
        layer_stack_t() = default;
        
        // Push a new layer onto the stack.
        void push_layer(layer_t* layer);
        
        // Pop the last layer off the stack.
        void pop_back();
        
        // Handle events.
        void on_event(const event_t& event);
        
        // Update
        void update(double delta_time);
        
        // Render
        void render();
        
    private:
        // The actual vector to hold the layers.
        std::vector<layer_t*> m_layer_stack;
    };
}

#endif /* BF230894_3A15_4E2F_B695_7A65ABE76764 */
