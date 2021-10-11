#ifndef ED800DE5_6D2D_45DD_94DB_E48B360E5217
#define ED800DE5_6D2D_45DD_94DB_E48B360E5217

namespace SCP
{
    class Scene
    {
    public:
        // Update the scene.
        virtual void update() = 0;
        
        // Render the scene.
        virtual void render() = 0;
        
        // Update the active scene
        static void updateActive() { active->update(); }
        
        // Render the active scene
        static void renderActive() { active->render(); }
        
        // Set the active scene.
        template<typename T>
        static void setActive()
        {
            if (active != nullptr)
            {
                delete active;
            }
            
            active = new T();
        }
        
        
        
        
        
        // Remove the active scene
        static void removeActive()
        {
            if (active != nullptr)
            {
                delete active;
            }
            
            active = nullptr;
        }
        
        // Destroys the scene.
        virtual ~Scene() {}
        
    private:
        // The active scene
        static Scene* active;
    };
}

#endif /* ED800DE5_6D2D_45DD_94DB_E48B360E5217 */
