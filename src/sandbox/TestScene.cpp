#include <iostream>

#include "TestScene.hpp"

TestScene::TestScene()
{
    std::cout << "[INFO]: Starting the test scene." << std::endl;
}




void TestScene::update()
{
    std::cout << "[INFO]: Updating the game." << std::endl;
}




void TestScene::render()
{
    std::cout << "[INFO]: Rendering the game." << std::endl;
}




TestScene::~TestScene()
{
    std::cout << "[INFO]: Switching out of the Test scene." << std::endl;
}