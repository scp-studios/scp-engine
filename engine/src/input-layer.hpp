#ifndef A7CFF258_7542_4682_B50A_5D658C9ACCBF
#define A7CFF258_7542_4682_B50A_5D658C9ACCBF

#include <scp/layer.hpp>

namespace scp
{
    class input_t;
    
    class input_layer_t: public layer_t
    {
    public:
        input_layer_t(input_t& input_object);
        
        bool on_event(const event_t& event) override;
        
        ~input_layer_t();
        
    private:
        // The reference to the Input object that is used.
        input_t& m_input_object;
    };
}

#endif /* A7CFF258_7542_4682_B50A_5D658C9ACCBF */
