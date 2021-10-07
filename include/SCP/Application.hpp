#ifndef B6E2234F_9198_4E97_98FB_59C6724D94A2
#define B6E2234F_9198_4E97_98FB_59C6724D94A2

namespace SCP
{
    // A base class for the application or game
    class Application
    {
    public:
        // Update
        virtual void update() = 0;
        
        // Render
        virtual void render() = 0;
        
        // Is the app still open?
        virtual bool isOpen() = 0;
    };
}

#endif /* B6E2234F_9198_4E97_98FB_59C6724D94A2 */
