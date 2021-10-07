#include <SCP/Application.hpp>
#include <SCP/AppLauncher.hpp>

using SCP::Application;
namespace AppLauncher = SCP::AppLauncher;

class Sandbox: public SCP::Application
{
public:
    void start() override
    {
        
    }
    
    
    
    
    void update() override
    {
        
    }
    
    
    
    
    void render() override
    {
        
    }
    
    
    
    
    bool isOpen() override
    {
        return true;
    }
    
    
    
    
    void stop() override
    {
        
    }
};




int main(int argc, char** argv)
{
    AppLauncher::launchApplication<Sandbox>(argc, argv);
}