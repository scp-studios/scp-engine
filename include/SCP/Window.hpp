#ifndef D8FB0E25_3C4E_4309_92B7_1FE409BEF648
#define D8FB0E25_3C4E_4309_92B7_1FE409BEF648

#include <SCP/pch.hpp>
#include <GLFW/glfw3.h>

#include <SCP/Events/KeyEvent.hpp>
#include <SCP/Events/MouseClickEvent.hpp>
#include <SCP/Events/MousePosEvent.hpp>

#include <SCP/EventQueue.hpp>

namespace SCP
{
    const int16_t SCREEN_WIDTH = -1;
    const int16_t SCREEN_HEIGHT = -2;
    
    struct WindowData
    {
        uint16_t m_width;
        uint16_t m_height;
    };
    
    // A wrapper class around a GLFW window. Simple. It only supports GLFW with OpenGL so far though.
    class Window
    {
    public:
        // Obtain the instance of this window
        static Window& getInstance(
            int16_t width = 640, 
            int16_t height = 480, 
            std::string_view title = "SCP Engine Game", 
            bool fullscreen = false,
            bool decorated = true
        );
        
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
            int16_t width, int16_t height, std::string_view title,
            bool fullscreen, bool decorated
        );
        
        // The handle to the actual window
        GLFWwindow* m_handle;
        
        // The structure containing all of the window's data
        WindowData m_data;
        
        // The key callback
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            EventQueue::getInstance().add(std::make_shared<Events::KeyEvent>(key));
        }
        
        // The mouse button callback
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
        {
            EventQueue::getInstance().add(std::make_shared<Events::MouseClickEvent>(button));
        }
        
        // The mouse position callback
        static void mousePositionCallback(GLFWwindow* window, double xpos, double ypos)
        {
            EventQueue::getInstance().add(std::make_shared<Events::MousePosEvent>(xpos, ypos));
        }
        
        // The framebuffer size callback
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        
        // The error callback
        static void errorCallback(int code, const char* msg)
        {
            std::cerr << "[GLFW ERROR]: " << msg << std::endl;
        }
    };
}

#endif /* D8FB0E25_3C4E_4309_92B7_1FE409BEF648 */
