#include "../../pch.hpp"

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <scp/event-dispatcher.hpp>
#include <scp/key.hpp>
#include <scp/events/key.hpp>
#include <scp/events/mouse.hpp>

#include "x11-keymap.hpp"

#include "x11-window.hpp"

using scp::platform::linux_n::x11_window_t;

const uint8_t Button6 = 6;
const uint8_t Button7 = 7;

x11_window_t::x11_window_t(int32_t p_width, int32_t p_height, std::string_view p_title, event_dispatcher_t& p_event_dispatcher, bool p_fullscreen): 
    m_width(p_width), m_height(p_height), m_fullscreen(p_fullscreen), m_keymap(x11_keymap_t::get_instance()), m_event_dispatcher(p_event_dispatcher)
{
    m_display_handle = XOpenDisplay(nullptr);
    if (!m_display_handle)
    {
        std::cerr << "[ERROR]: Failed to open an X Display connection.\n";
        m_is_open = false;
        return;
    }
    
    // Initialize the atoms that are needed.
    NET_WM_STATE = XInternAtom(m_display_handle, "_NET_WM_STATE", false);
    NET_WM_STATE_FULLSCREEN = XInternAtom(m_display_handle, "_NET_WM_STATE_FULLSCREEN", false);
    NET_WM_BYPASS_COMPOSITOR = XInternAtom(m_display_handle, "_NET_WM_BYPASS_COMPOSITOR", false);
    WM_DELETE_WINDOW = XInternAtom(m_display_handle, "WM_DELETE_WINDOW", False);
    WM_PROTOCOLS = XInternAtom(m_display_handle, "WM_PROTOCOLS", False);
    
    int32_t screen = DefaultScreen(m_display_handle);
    
    m_is_open = true;
    
    m_handle = XCreateSimpleWindow(
        m_display_handle, // The display to create the window on.
        DefaultRootWindow(m_display_handle), // The parent window.
        0, // X Position on the screen. 0 means ignore.
        0, // Y position on the screen
        p_width, // width
        p_height, // height
        0, // border width
        WhitePixel(m_display_handle, screen),
        BlackPixel(m_display_handle, screen)
    );
    if (!m_handle)
    {
        m_is_open = false;
        return;
    }
    
    XStoreName(m_display_handle, m_handle, p_title.data());
    
    XSelectInput(m_display_handle, m_handle, KeyPressMask | KeyReleaseMask | ButtonPressMask | ButtonReleaseMask | PointerMotionMask);
    
    XSetWMProtocols(m_display_handle, m_handle, &WM_DELETE_WINDOW, 1);
    
    if (p_fullscreen)
    {
        XEvent* fullscreen_event = new XEvent;
        fullscreen_event->type = ClientMessage;
        fullscreen_event->xclient.window = m_handle;
        fullscreen_event->xclient.format = 32;
        fullscreen_event->xclient.message_type = NET_WM_STATE;
        fullscreen_event->xclient.data.l[0] = 1;
        fullscreen_event->xclient.data.l[1] = NET_WM_STATE_FULLSCREEN;
        
        XSendEvent(m_display_handle, DefaultRootWindow(m_display_handle), false, ClientMessage, fullscreen_event);
        
        // Bypass the compositor so that things like G sync would work.
        const uint64_t value = 1;
        XChangeProperty(m_display_handle, m_handle, NET_WM_BYPASS_COMPOSITOR, XA_CARDINAL, 32, PropModeReplace, reinterpret_cast<const unsigned char*>(&value), 1);
        
        delete fullscreen_event;
    }
}

bool x11_window_t::is_open_impl() const 
{
    return m_is_open;
}

void x11_window_t::show_impl() const
{
    XMapWindow(m_display_handle, m_handle);
    
    // Obtain the width and height of the screen.
    int32_t width = XDisplayWidth(m_display_handle, DefaultScreen(m_display_handle));
    int32_t height = XDisplayHeight(m_display_handle, DefaultScreen(m_display_handle));
    
    // Move the window to the center of the screen.
    XMoveWindow(m_display_handle, m_handle, (width - m_width) / 2, (height - m_height) / 2);
}

void x11_window_t::set_fullscreen_impl(bool p_value)
{
    if (p_value)
    {
        XEvent *fullscreen_event = new XEvent;
        fullscreen_event->type = ClientMessage;
        fullscreen_event->xclient.window = m_handle;
        fullscreen_event->xclient.format = 32;
        fullscreen_event->xclient.message_type = NET_WM_STATE;
        fullscreen_event->xclient.data.l[0] = 1;
        fullscreen_event->xclient.data.l[1] = NET_WM_STATE_FULLSCREEN;
        
        XSendEvent(m_display_handle, DefaultRootWindow(m_display_handle), false, ClientMessage, fullscreen_event);
        
        // Bypass the compositor so that things like G sync would work.
        const uint64_t value = 1;
        XChangeProperty(m_display_handle, m_handle, NET_WM_BYPASS_COMPOSITOR, XA_CARDINAL, 32, PropModeReplace, reinterpret_cast<const unsigned char*>(&value), 1);
        
        delete fullscreen_event;
    }
    else 
    {
        XEvent *fullscreen_event = new XEvent;
        fullscreen_event->type = ClientMessage;
        fullscreen_event->xclient.window = m_handle;
        fullscreen_event->xclient.format = 32;
        fullscreen_event->xclient.message_type = NET_WM_STATE;
        fullscreen_event->xclient.data.l[0] = 0;
        fullscreen_event->xclient.data.l[1] = NET_WM_STATE_FULLSCREEN;
        
        XSendEvent(m_display_handle, DefaultRootWindow(m_display_handle), false, ClientMessage, fullscreen_event);
        
        // Bypass the compositor so that things like G sync would work.
        const uint64_t value = 0;
        XChangeProperty(m_display_handle, m_handle, NET_WM_BYPASS_COMPOSITOR, XA_CARDINAL, 32, PropModeReplace, reinterpret_cast<const unsigned char*>(&value), 1);
        
        delete fullscreen_event;
    }
}

void x11_window_t::update_impl()
{
    handle_events();
}

static inline scp::mouse_button_t translate_button_code(uint32_t p_og)
{
    switch (p_og)
    {
        case Button1:
            return scp::mouse_button_t::LEFT;
        case Button2:
            return scp::mouse_button_t::MIDDLE;
        case Button3:
            return scp::mouse_button_t::RIGHT;
        default:
            // Assume that the left mouse is clicked if the button number isn't
            // known.
            return scp::mouse_button_t::LEFT;
    }
}

void x11_window_t::handle_events()
{
    if (XPending(m_display_handle) > 0)
    {
        XEvent event;
        XNextEvent(m_display_handle, &event);
        
        switch (event.type)
        {
        case ClientMessage:
            std::cout << "Hello!" << std::endl;
            if ((event.xclient.message_type == WM_PROTOCOLS) && (event.xclient.data.l[0] == WM_DELETE_WINDOW))
            {
                m_is_open = false;
                break;
            }
        case MappingNotify:
            XRefreshKeyboardMapping(&event.xmapping);
            break;
        case KeyPress:
            {
                events::key_t out_event = {};
                out_event.key_code = m_keymap.get_key_enum(XLookupKeysym(&event.xkey, 0));
                out_event.type = events::key_t::key_type_t::PRESS;
                
                m_event_dispatcher.dispatch(out_event);
            }
            break;
        case KeyRelease:
            {
                events::key_t out_event = {};
                out_event.key_code = m_keymap.get_key_enum(XLookupKeysym(&event.xkey, 0));
                out_event.type = events::key_t::key_type_t::RELEASE;
                
                m_event_dispatcher.dispatch(out_event);
            }
            break;
        case ButtonPress:
            {
                if (event.xbutton.button > Button3)
                {
                    double scroll_x = 0.0;
                    double scroll_y = 0.0;
                    
                    switch (event.xbutton.button)
                    {
                        case Button4:
                            scroll_y = 1.0;
                            break;
                        case Button5:
                            scroll_y = -1.0;
                            break;
                        case Button6:
                            scroll_x = 1.0;
                            break;
                        case Button7:
                            scroll_x = -1.0;
                            break;
                    }
                    
                    events::scroll_t out_event = {};
                    out_event.x = scroll_x;
                    out_event.y = scroll_y;
                    
                    m_event_dispatcher.dispatch(out_event);
                }
                else 
                {
                    events::mouse_button_t out_event = {};
                    out_event.mouse_code = translate_button_code(event.xbutton.button);
                    out_event.is_button_down = false;
                    
                    m_event_dispatcher.dispatch(out_event);
                }
            }
            break;
        case ButtonRelease:
            {
                events::mouse_button_t out_event = {};
                out_event.mouse_code = translate_button_code(event.xbutton.button);
                out_event.is_button_down = false;
                
                m_event_dispatcher.dispatch(out_event);
            }
        case MotionNotify:
            {
                events::mouse_position out_event = {};
                out_event.x = event.xmotion.x;
                out_event.y = event.xmotion.y;
                
                m_event_dispatcher.dispatch(out_event);
            }
        }
    }
}

x11_window_t::~x11_window_t()
{
    XDestroyWindow(m_display_handle, m_handle);
    XCloseDisplay(m_display_handle);
}