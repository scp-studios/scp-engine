#ifndef BED65B2C_50ED_40D6_BAAB_58756049B956
#define BED65B2C_50ED_40D6_BAAB_58756049B956

#include <unordered_map>

namespace scp
{
    enum class key_t;
}

namespace scp::platform::linux_n
{
    // A singleton class for keymapping between my key enums to X11 keycodes
    class x11_keymap_t
    {
    public:
        // Get the instance.
        x11_keymap_t& get_instance() const;
        
        // Begone!
        x11_keymap_t(x11_keymap_t&) = delete;
        
        // Returns the key enumeration corresponding to the X11 keycode
        key_t get_key_enum(uint32_t x11_keycode);
        
    private:
        // Private constructor because we still have to construct the thing.
        x11_keymap_t();
        
        // The actual keymap.
        std::unordered_map<uint32_t, key_t> m_keymap;
    };
}

#endif /* BED65B2C_50ED_40D6_BAAB_58756049B956 */
