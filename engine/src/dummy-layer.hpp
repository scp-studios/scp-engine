#ifndef BB8D2F7D_BE9D_41C8_9462_2E26C1C55037
#define BB8D2F7D_BE9D_41C8_9462_2E26C1C55037

#include <scp/layer.hpp>

namespace scp
{
    // A simple dummy layer used for certain testing purposes. Might be removed
    // in the future.
    class dummy_layer_t: public layer_t
    {
    public:
        ~dummy_layer_t() {}
    };
}

#endif /* BB8D2F7D_BE9D_41C8_9462_2E26C1C55037 */
