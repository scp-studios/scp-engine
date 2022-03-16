#ifndef E14B4201_22FB_4078_AB53_537BB0282B76
#define E14B4201_22FB_4078_AB53_537BB0282B76

// This contains all of the key codes for the SCP Engine. It's a lot.
// Please note that some keys may not be on here.

namespace scp
{
    enum class key_t
    {
        // First row.
        // ==========
        ESCAPE,
        
        // function keys
        F1,
        F2,
        F3,
        F4,
        F5,
        F6,
        F7,
        F8,
        F9,
        F10,
        F11,
        F12,
        
        // Second row.
        // ==========
        
        GRAVE_ACCENT,
        
        // Numbers
        ONE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        ZERO,
        
        HYTHEN,
        EQUAL_SIGN,
        
        BACKSPACE,
        
        // Third row.
        // ==========
        
        TAB,
        
        Q,
        W,
        E,
        R,
        T,
        Y,
        U,
        I,
        O,
        P,
        
        LEFT_SQUARE_BRACKET, 
        RIGHT_SQUARE_BRACKET,
        
        BACK_SLASH,
        
        // Fourth row.
        // =========
        
        CAPS_LOCK,
        
        A,
        S,
        D,
        F,
        G,
        H,
        J,
        K,
        L,
        
        SEMICOLON,
        QUOTE,
        ENTER,
        
        // Fifth row.
        // ========
        
        LEFT_SHIFT,
        
        Z,
        X,
        C,
        V,
        B,
        N,
        M,
        
        COMMA,
        PERIOD,
        FORWARD_SLASH,
        
        RIGHT_SHIFT,
        
        // Sixth row
        // ========
        
        LEFT_CONTROL,
        LEFT_SUPER,
        LEFT_ALT,
        
        SPACE,
        
        RIGHT_ALT,
        RIGHT_SUPER,
        MENU,
        RIGHT_CONTROL,
        
        // Miscallaneous
        // ========
        
        // Arrow keys
        UP, 
        LEFT,
        DOWN,
        RIGHT,
        
        // Some other keys.
        INSERT,
        HOME,
        PAGE_UP,
        DELETE,
        END,
        PAGE_DOWN,
        
        // Number pad keys
        NUM_LOCK,
        NUMBER_PAD_FORWARD_SLASH,
        NUMBER_PAD_ASTERIKS,
        NUMBER_PAD_HYPHEN,
        NUMBER_PAD_PLUS,
        NUMBER_PAD_ENTER,
        NUMBER_PAD_DEL,
        
        // Number pad number keys
        NUMBER_PAD_1,
        NUMBER_PAD_2,
        NUMBER_PAD_3,
        NUMBER_PAD_4,
        NUMBER_PAD_5,
        NUMBER_PAD_6,
        NUMBER_PAD_7,
        NUMBER_PAD_8,
        NUMBER_PAD_9,
        NUMBER_PAD_0
    };
}

#endif /* E14B4201_22FB_4078_AB53_537BB0282B76 */
