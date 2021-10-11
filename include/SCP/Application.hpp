#ifndef B6E2234F_9198_4E97_98FB_59C6724D94A2
#define B6E2234F_9198_4E97_98FB_59C6724D94A2

#include <SCP/Scene.hpp>

namespace SCP
{
    // A base class for the application or game
    template<typename StartScene>
    class Application
    {
    public:
        // Constructor
        Application()
        {
            Scene::setActive<StartScene>();
        }
        
        
        
        
        
        // Update
        void update()
        {
            Scene::updateActive();
        }
        
        
        
        
        
        // Render
        void render()
        {
            Scene::renderActive();
        }
        
        
        
        
        
        // Destructor
        ~Application()
        {
            Scene::removeActive();
        }
    };
}

#endif /* B6E2234F_9198_4E97_98FB_59C6724D94A2 */
