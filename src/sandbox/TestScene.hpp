#ifndef C82FE54A_E853_4B6F_8A88_7BEB57D52D9E
#define C82FE54A_E853_4B6F_8A88_7BEB57D52D9E

#include <SCP/Scene.hpp>

class TestScene: public SCP::Scene
{
public:
    TestScene();
    
    void update() override;
    
    void render() override;
    
    ~TestScene();
}

#endif /* C82FE54A_E853_4B6F_8A88_7BEB57D52D9E */
