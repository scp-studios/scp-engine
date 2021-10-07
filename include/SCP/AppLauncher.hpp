#ifndef D7BB7F5C_3B43_4A7E_9DCF_E7A16BB70115
#define D7BB7F5C_3B43_4A7E_9DCF_E7A16BB70115

#include <stdexcept>
#include <iostream>

namespace SCP
{
    class Application;
    
    namespace AppLauncher
    {
        // Simple function that basically just lauches an Application.
        template<typename AppClass>
        int launchApplication(int argc, char** argv)
        {
            try
            {
                AppClass app;
                while (app.isOpen())
                {
                    app.update();
                    app.render();
                }
            } catch (std::runtime_error& e)
            {
                std::cerr << "[FATAL ERROR]: " << e.what() << std::endl;
                return -1;
            }
            
            return 0;
        }
    }
}

#endif /* D7BB7F5C_3B43_4A7E_9DCF_E7A16BB70115 */
