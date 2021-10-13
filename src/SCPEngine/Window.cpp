#include <SCP/pch.hpp>

#include <SCP/Window.hpp>

using SCP::Window;

using SCP::Events::KeyEvent;
using SCP::Events::MouseClickEvent;
using SCP::Events::MousePosEvent;

Window& Window::getInstance(
    int16_t width, 
    int16_t height, 
    std::string_view title, 
    bool fullscreen,
    bool decorated
)
{
    static Window window(width, height, title, fullscreen, decorated);
    return window;
}





void Window::update()
{
    glfwSwapBuffers(m_handle);
    glfwPollEvents();
}





Window::~Window()
{
    glfwDestroyWindow(m_handle);
    glfwTerminate();
}




Window::Window(
    int16_t width, int16_t height, std::string_view title,
    bool fullscreen, bool decorated
) {
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
    
    glfwSetErrorCallback(errorCallback);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_DECORATED, decorated);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    GLFWmonitor* monitor = nullptr;
    
    if (fullscreen)
    {
        monitor = glfwGetPrimaryMonitor();
    }
    
    const GLFWvidmode* videoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
    
    if (width == SCREEN_WIDTH)
    {
        m_data.m_width = videoMode->width;
    } else 
    {
        m_data.m_width = width;
    }
    
    if (height == SCREEN_HEIGHT)
    {
        m_data.m_height = videoMode->height;
    } else
    {
        m_data.m_height = height;
    }
    
    m_handle = glfwCreateWindow(m_data.m_width, m_data.m_height, title.data(), monitor, nullptr);
    if (m_handle == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window.");
    }
    
    glfwMakeContextCurrent(m_handle);
    
    glfwSetKeyCallback(m_handle, keyCallback);
    glfwSetMouseButtonCallback(m_handle, mouseButtonCallback);
    glfwSetCursorPosCallback(m_handle, mousePositionCallback);
    glfwSetWindowCloseCallback(m_handle, windowCloseCallback);
    
    glfwSetWindowUserPointer(m_handle, &m_data);
}





void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
    WindowData* user = reinterpret_cast<WindowData*>(glfwGetWindowUserPointer(window));
    user->m_width = width;
    user->m_height = height;
}