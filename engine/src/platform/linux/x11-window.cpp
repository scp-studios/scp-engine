#include "../../pch.hpp"

#include <X11/Xlib.h>

#include "x11-window.hpp"

using scp::platform::linux_n::x11_window_t;

x11_window_t::x11_window_t(int32_t p_width, int32_t p_height, std::string_view p_title, bool p_fullscreen): m_width(p_width), m_height(p_height)
{
    m_display_handle = XOpenDisplay(nullptr);
    if (!m_display_handle)
    {
        std::cerr << "[ERROR]: Failed to open an X Display connection.\n";
        m_is_open = false;
        return;
    }
    
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
    
    WM_DELETE_WINDOW = XInternAtom(m_display_handle, "WM_DELETE_WINDOW", False);
    WM_PROTOCOLS = XInternAtom(m_display_handle, "WM_PROTOCOLS", False);
    
    XSetWMProtocols(m_display_handle, m_handle, &WM_DELETE_WINDOW, 1);
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

void x11_window_t::update_impl()
{
    handle_events();
}

void x11_window_t::handle_events()
{
    while (XPending(m_display_handle) > 0)
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
        }
    }
}

x11_window_t::~x11_window_t()
{
    XDestroyWindow(m_display_handle, m_handle);
    XCloseDisplay(m_display_handle);
}