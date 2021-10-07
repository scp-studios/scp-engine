#include <SCP/Application.hpp>
#include <SCP/AppLauncher.hpp>

using SCP::Application;
namespace AppLauncher = SCP::AppLauncher;

class Sandbox: public SCP::Application
{
public:
    Sandbox()
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
    
    
    
    
    ~Sandbox()
    {
        
    }
};

SCP_LAUNCH_APPLICATION(Sandbox)