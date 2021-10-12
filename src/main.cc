#include<iostream>
#include "Game.hh"

int main()
{
   //sf::RenderWindow* window{new sf::RenderWindow(sf::VideoMode(800, 800), "Game1")};
  //sf::Event* event{new sf::Event()};

  /*sf::RectangleShape* rectangleShape{new sf::RectangleShape(sf::Vector2f(100, 100))};
  rectangleShape->setPosition(sf::Vector2f(200, 50));
  rectangleShape->setFillColor(sf::Color::Red);
  rectangleShape->setOutlineThickness(1);
  rectangleShape->setOutlineColor(sf::Color::Green);*/

  Game* game{new Game()};
  game->Initialize();

  delete game;

  return EXIT_SUCCESS;

}