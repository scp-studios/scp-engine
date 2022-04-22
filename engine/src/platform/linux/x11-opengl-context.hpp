#ifndef D4FA2297_F00F_4AF5_88DF_5302E8EF8E00
#define D4FA2297_F00F_4AF5_88DF_5302E8EF8E00

namespace scp
{
    class window_t;
}

#include <GL/glx.h>

namespace scp::platform::linux
{
    // A simple class for creating an OpenGL context with the X11 and GLX stuff
    // . Pretty simple for now, though it may get more complex in the future.
    class x11_opengl_context_t
    {
        // Requires a window to be created
        explicit x11_opengl_context_t(const window_t& window);
        
        // Makes the context current.
        void make_current() const noexcept;
        
        // Makes the context not current.
        void make_not_current() const noexcept;
        
        // Destroys the the context.
        ~x11_opengl_context_t();
    };
}

#endif /* D4FA2297_F00F_4AF5_88DF_5302E8EF8E00 */
