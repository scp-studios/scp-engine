#include <iostream>
#include <SCP/Window.hpp>

#include "TestScene.hpp"

using SCP::Window;

TestScene::TestScene()
{
    Window& window = Window::getInstance(1280, 720, "Sandbox", false, true);
    
    window.show();
}




void TestScene::update()
{
    Window::getInstance().update();
}




void TestScene::render()
{
   
}




TestScene::~TestScene()
{
    
}