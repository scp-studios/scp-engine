#ifndef D986E897_63DF_449A_814D_B416389B80DB
#define D986E897_63DF_449A_814D_B416389B80DB

// The layer that is in charge of the scene (or at least the currently active
// one.)

#include <scp/scp.hpp>
#include <scp/layer.hpp>

namespace scp
{
    class scene_layer_t: public layer_t
    {
    public:
        scene_layer_t() = default;
        
        void update(double delta_time) override;
        
        void render() override;
        
        void on_event(const event_t& event) override;
        
        ~scene_layer_t();
    };
}

#endif /* D986E897_63DF_449A_814D_B416389B80DB */
