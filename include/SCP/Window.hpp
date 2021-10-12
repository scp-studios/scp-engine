#ifndef D8FB0E25_3C4E_4309_92B7_1FE409BEF648
#define D8FB0E25_3C4E_4309_92B7_1FE409BEF648

#include <SCP/pch.hpp>
#include <GLFW/glfw3.h>

namespace SCP
{
    const int16_t SCREEN_WIDTH = -1;
    const int16_t SCREEN_HEIGHT = -2;
    
    struct WindowData
    {
        uint16_t m_width;
        uint16_t m_height;
    };
    
    // A wrapper class around a GLFW window. Simple.
    class Window
    {
    public:
        // Obtain the instance of this window
        static Window& getInstance();
        
        // The window is hidden by default, so use this function to show it.
        void show() { glfwShowWindow(m_handle); }
        
        // Is the window still Open?
        bool isOpen() { return !glfwWindowShouldClose(m_handle); }
        
        // Update the window
        void update();
        
        // Destroys the window
        ~Window();
        
    private:
        // Constructor
        Window(
            int16_t width = 640, 
            int16_t height = 480, 
            std::string_view title = "SCP Engine Game", 
            bool fullscreen = false,
            bool decorated = true
        );
        
        // The handle to the actual window
        GLFWwindow* m_handle;
        
        // The structure containing all of the window's data
        WindowData data;
        
        // The key callback
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
        
        // The mouse button callback
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        
        // The mouse position callback
        static void mousePositionCallback(GLFWwindow* window, double xpos, double ypos);
        
        // The framebuffer size callback
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
    };
}

#endif /* D8FB0E25_3C4E_4309_92B7_1FE409BEF648 */
