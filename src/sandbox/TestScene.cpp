#include <iostream>
#include <SCP/Window.hpp>

#include "TestScene.hpp"

using SCP::Window;

TestScene::TestScene()
{
    Window::getInstance(1280, 720, "Sandbox", false, true);
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