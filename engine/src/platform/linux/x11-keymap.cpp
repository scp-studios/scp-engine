#include "../../pch.hpp"

#define XK_LATIN1
#define XK_MISCELLANY
#include <X11/keysymdef.h>

#include <scp/key.hpp>

#include "x11-keymap.hpp"

using scp::platform::linux_n::x11_keymap_t;

#define INSERT_KEY_S(a, b) m_keymap.insert({ XK_##a, scp::key_t::b })
#define INSERT_KEY(x) m_keymap.insert({ XK_##x, scp::key_t::x })

x11_keymap_t& x11_keymap_t::get_instance()
{
    static x11_keymap_t instance;
    return instance;
}

scp::key_t x11_keymap_t::get_key_enum(uint32_t p_x11_keycode)
{
    return m_keymap.at(p_x11_keycode);
}

x11_keymap_t::x11_keymap_t()
{
    INSERT_KEY_S(Escape, ESCAPE);
    INSERT_KEY(F1);
    INSERT_KEY(F2);
    INSERT_KEY(F3);
    INSERT_KEY(F4);
    INSERT_KEY(F5);
    INSERT_KEY(F6);
    INSERT_KEY(F7);
    INSERT_KEY(F8);
    INSERT_KEY(F9);
    INSERT_KEY(F10);
    INSERT_KEY(F11);
    INSERT_KEY(F12);
    
    INSERT_KEY_S(grave, GRAVE_ACCENT);
    INSERT_KEY_S(1, ONE);
    INSERT_KEY_S(2, TWO);
    INSERT_KEY_S(3, THREE);
    INSERT_KEY_S(4, FOUR);
    INSERT_KEY_S(5, FIVE);
    INSERT_KEY_S(6, SIX);
    INSERT_KEY_S(7, SEVEN);
    INSERT_KEY_S(8, EIGHT);
    INSERT_KEY_S(9, NINE);
    INSERT_KEY_S(0, ZERO);
    INSERT_KEY_S(hyphen, HYTHEN);
    INSERT_KEY_S(equal, EQUAL_SIGN);
    INSERT_KEY_S(BackSpace, BACKSPACE);
    
    INSERT_KEY_S(Tab, TAB);
    INSERT_KEY_S(q, Q);
    INSERT_KEY_S(w, W);
    INSERT_KEY_S(e, E);
    INSERT_KEY_S(r, R);
    INSERT_KEY_S(t, T);
    INSERT_KEY_S(y, Y);
    INSERT_KEY_S(u, U);
    INSERT_KEY_S(i, I);
    INSERT_KEY_S(o, O);
    INSERT_KEY_S(p, P);
    INSERT_KEY_S(bracketleft, LEFT_SQUARE_BRACKET);
    INSERT_KEY_S(bracketright, RIGHT_SQUARE_BRACKET);
    INSERT_KEY_S(backslash, BACK_SLASH);
    
    INSERT_KEY_S(Caps_Lock, CAPS_LOCK);
    INSERT_KEY_S(a, A);
    INSERT_KEY_S(s, S);
    INSERT_KEY_S(d, D);
    INSERT_KEY_S(f, F);
    INSERT_KEY_S(g, G);
    INSERT_KEY_S(h, H);
    INSERT_KEY_S(j, J);
    INSERT_KEY_S(k, K);
    INSERT_KEY_S(l, L);
    INSERT_KEY_S(semicolon, SEMICOLON);
    INSERT_KEY_S(Return, ENTER);
    
    INSERT_KEY_S(Shift_L, LEFT_SHIFT);
    INSERT_KEY_S(z, Z);
    INSERT_KEY_S(x, X);
    INSERT_KEY_S(c, C);
    INSERT_KEY_S(v, V);
    INSERT_KEY_S(b, B);
    INSERT_KEY_S(n, N);
    INSERT_KEY_S(m, M);
    INSERT_KEY_S(Shift_R, RIGHT_SHIFT);
    
    INSERT_KEY_S(Control_L, LEFT_CONTROL);
    INSERT_KEY_S(Super_L, LEFT_SUPER);
    INSERT_KEY_S(Alt_L, LEFT_ALT);
    INSERT_KEY_S(space, SPACE);
    INSERT_KEY_S(Control_R, RIGHT_CONTROL);
    INSERT_KEY_S(Super_R, RIGHT_SUPER);
    INSERT_KEY_S(Alt_R, RIGHT_ALT);
    
    INSERT_KEY_S(Up, UP);
    INSERT_KEY_S(Left, LEFT);
    INSERT_KEY_S(Down, DOWN);
    INSERT_KEY_S(Right, RIGHT);
    
    INSERT_KEY_S(Insert, INSERT);
    INSERT_KEY_S(Home, HOME);
    INSERT_KEY_S(Page_Up, PAGE_UP);
    INSERT_KEY_S(Delete, DELETE);
    INSERT_KEY_S(End, END);
    INSERT_KEY_S(Page_Down, PAGE_DOWN);
    
    INSERT_KEY_S(Num_Lock, NUM_LOCK);
    INSERT_KEY_S(KP_Divide, NUMBER_PAD_FORWARD_SLASH);
    INSERT_KEY_S(KP_Multiply, NUMBER_PAD_ASTERIKS);
    INSERT_KEY_S(KP_Subtract, NUMBER_PAD_HYPHEN);
    INSERT_KEY_S(KP_Add, NUMBER_PAD_PLUS);
    INSERT_KEY_S(KP_Enter, NUMBER_PAD_ENTER);
    INSERT_KEY_S(KP_Delete, NUMBER_PAD_DEL);
    
    INSERT_KEY_S(KP_0, NUMBER_PAD_0);
    INSERT_KEY_S(KP_1, NUMBER_PAD_1);
    INSERT_KEY_S(KP_2, NUMBER_PAD_2);
    INSERT_KEY_S(KP_3, NUMBER_PAD_3);
    INSERT_KEY_S(KP_4, NUMBER_PAD_4);
    INSERT_KEY_S(KP_5, NUMBER_PAD_5);
    INSERT_KEY_S(KP_6, NUMBER_PAD_6);
    INSERT_KEY_S(KP_7, NUMBER_PAD_7);
    INSERT_KEY_S(KP_8, NUMBER_PAD_8);
    INSERT_KEY_S(KP_9, NUMBER_PAD_9);
}