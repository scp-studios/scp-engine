#ifndef BF212232_142F_4422_9ACE_9CE85A1040BA
#define BF212232_142F_4422_9ACE_9CE85A1040BA

// A basic, multi-purposed layer system. It is pretty simple for now.
//
// Okay, so the basic philosophy behind my layer design is that we have this l-
// ayer stack, and that layer stack is basically just propagates stuff through 
// all of the layers.

#include <scp/scp.hpp>

namespace scp
{
    class SCPEXP event_t;
    
    class SCPEXP layer_t
    {
    public:
        layer_t() = default;
        
        // Update the layer, and called every frame. Some layers may not need  
        // this sort of functionality (such as render-only layers) and so it is
        // optional.
        virtual void update(double delta_time) { SCP_UNUSED_ARG(delta_time); };
        
        // Render the layer (not applicable for some layers, so it is marked as
        // optional).
        virtual void render() {}
        
        // Handle events. The return value is whether the event should propaga-
        // te further throughout the layer stack.
        virtual bool on_event(const event_t& event) { SCP_UNUSED_ARG(event); return true; }
        
        // Destroy the layer.
        virtual ~layer_t() {};
    };
}

#endif /* BF212232_142F_4422_9ACE_9CE85A1040BA */
