#pragma once
#include<SFML/Graphics.hpp>


class Game
{
private:
    sf::RenderWindow* window{};
    sf::Event* event{};
public:
    Game(/* args */);
    ~Game();
    void Initialize();
    void Update();
    void Render();
    void Input();
    void Start();
    void Draw();
    void MainLoop();
    void Destroy();
};
