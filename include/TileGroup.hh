#pragma once
#include "Tile.hh"

class TileGroup
{
private:
  sf::RenderWindow* window;
  std::vector<Tile*>* tiles;
public:
  TileGroup(sf::RenderWindow*& window);
  ~TileGroup();

  void GenerateMap();
  void Draw();
};