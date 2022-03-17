#ifndef BD565510_3080_4DE8_A662_8A0F6E4C9708
#define BD565510_3080_4DE8_A662_8A0F6E4C9708

// This is the Linux implementation of the Window class. Unlike the Windows im-
// plementation, this version actually has working fullscreen mode.

#include <scp/window.hpp>

typedef unsigned long Window;
typedef unsigned long Atom;
typedef struct _XDisplay Display;

namespace scp::platform::linux_n
{
    class x11_window_t: public scp::window_t
    {
    public:
        x11_window_t(int32_t width, int32_t height, std::string_view title, event_dispatcher_t& event_dispatcher, bool fullscreen);
        
        // Removed the copy constructor and assignment operators to prevent pr-
        // oblems in the future.
        x11_window_t(x11_window_t&) = delete;
        x11_window_t& operator=(x11_window_t&) = delete;
        
        // Returns whether the window is open or not.
        bool is_open_impl() const override;
        
        // Show the window.
        void show_impl() const override;
        
        // Change the window in and out of fullscreen.
        void set_fullscreen_impl(bool value) override;
        
        // Update the window.
        void update_impl() override;
        
        // Destructor
        ~x11_window_t();
        
    private:
        // The actual window handle.
        Window m_handle;
        
        // The pointer to the X Display handle
        Display* m_display_handle;
        
        // Whether the window is open or not.
        bool m_is_open;
        
        // The width and height of the window.
        uint16_t m_width;
        uint16_t m_height;
        
        // X11 window atoms. They technically don't change throughout the prog-
        // ram, but they can't be const because I have to past a non-const poi-
        // nter to X11 at some point.
        Atom WM_DELETE_WINDOW;
        Atom WM_PROTOCOLS;
        Atom NET_WM_STATE;
        Atom NET_WM_STATE_FULLSCREEN;
        Atom NET_WM_BYPASS_COMPOSITOR;
        
        // The event dispatcher to dispatch events to.
        event_dispatcher_t& m_event_dispatcher;
        
        // Is the window in fullscreen?
        bool m_fullscreen;
        
        // Handle the events.
        void handle_events();
    };
}

#endif /* BD565510_3080_4DE8_A662_8A0F6E4C9708 */
