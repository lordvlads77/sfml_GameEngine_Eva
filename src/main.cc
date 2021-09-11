#include <iostream>
#include "Game.hh"


int main()
{
    /*Sintaxis de las cosas especificas en los corchetes*/
    //sf::RenderWindow* window{new sf::RenderWindow(sf::VideoMode(800, 800), "Game1")};
    //sf::Event* event{new sf::Event()};

    /*Para crear los rectangulitos
    sf::RectangleShape* rectangleShape{new sf::RectangleShape(sf::Vector2f(100,100))};
    rectangleShape->setPosition(sf::Vector2f(200, 50));
    rectangleShape->setFillColor(sf::Color::Blue);
    rectangleShape->setOutlineThickness(5);
    rectangleShape->setOutlineColor(sf::Color::Green);*/
    
    //main loop
    //Event processing
    
    Game* game{new Game()};
    game->Initialize();

    delete game;

    return EXIT_SUCCESS;
    
}