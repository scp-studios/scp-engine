#ifndef FA08338D_60A0_43B6_8665_8118B5EB6E01
#define FA08338D_60A0_43B6_8665_8118B5EB6E01

#include <SCP/Events/KeyEvent.hpp>
#include <SCP/Events/MouseClickEvent.hpp>
#include <SCP/Events/MousePosEvent.hpp>

namespace SCP
{
    // A base class for a layer
    class Layer {
    public:
        Layer() {}
        
        // Update
        virtual void update() = 0;
        
        // Render
        virtual void render() = 0;
        
        // Events
        virtual bool onKeyEvent(const Events::KeyEvent& e) { return false; }
        virtual bool onMouseClickEvent(const Events::MouseClickEvent& e) { return false; }
        virtual bool onMousePosEvent(const Events::MousePosEvent& e) { return false; }
        
        virtual ~Layer();
    };
}

#endif /* FA08338D_60A0_43B6_8665_8118B5EB6E01 */
