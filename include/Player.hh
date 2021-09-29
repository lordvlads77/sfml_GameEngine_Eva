#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include<iostream>
#include "Rigidbody.hh"

class Player
{
private:
  std::string textureUrl{};
  float playerScale{};
  int width{};
  int height{};
  int column{};
  int row{};
  float posX{};
  float posY{};
  sf::Sprite* sprite;
  sf::Texture* texture;
  float playerSpeed{};
  Rigidbody* rigidbody{};

  void FlipSprite();
public:
  Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float playerSpeed, b2World*& world);
  Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float posX, float posY, float playerSpeed, 
  b2World*& world);
  ~Player();
  sf::Sprite* GetSprite() const;
  void Move();

  void Update();
};