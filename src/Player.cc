#include "Player.hh"
#include "InputSystem.hh"

Player::Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float playerSpeed, b2World*& world)
{
  this->textureUrl = textureUrl;
  this->playerScale = playerScale;
  this->width = width;
  this->height = height;
  this->column = column;
  this->row = row;
  this->playerSpeed = playerSpeed;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(column * width, row * height, width, height));
  sprite->setPosition(posX, posY);
  sprite->setColor(sf::Color::White);
  sprite->setScale(playerScale, playerScale);
  sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getOrigin().y);

   rigidbody = new Rigidbody(world, b2BodyType::b2_dynamicBody, 
  new b2Vec2(sprite->getPosition().x, sprite->getPosition().y), 
  16, 16, 1, 0, 0, new b2Vec2(sprite->getOrigin().x, sprite->getOrigin().y), 
  0.f);

}
Player::Player(std::string textureUrl, float playerScale, int width, int height, int column, int row, float posX, float posY, float playerSpeed, b2World*& world)
{
  this->textureUrl = textureUrl;
  this->playerScale = playerScale;
  this->width = width;
  this->height = height;
  this->column = column;
  this->row = row;
  this->posX = posX;
  this->posY = posY;
  this->playerSpeed = playerSpeed;

  texture = new sf::Texture();
  texture->loadFromFile(textureUrl);
  sprite = new sf::Sprite(*texture, sf::IntRect(column * width, row * height, width, height));
  sprite->setPosition(posX, posY);
  sprite->setColor(sf::Color::White);
  sprite->setScale(playerScale, playerScale);
  sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getOrigin().y);

  rigidbody = new Rigidbody(world, b2BodyType::b2_dynamicBody, 
  new b2Vec2(sprite->getPosition().x, sprite->getPosition().y), 
  16, 16, 1, 0, 0, new b2Vec2(sprite->getOrigin().x, sprite->getOrigin().y), 
  0.f);
}

Player::~Player()
{
}

sf::Sprite* Player::GetSprite() const
{
  return sprite;
}

void Player::Update()
{
  sprite->setPosition(rigidbody->GetBody()->GetPosition().x, 
  -rigidbody->GetBody()->GetPosition().y);
}

void Player::Move()
{
  rigidbody->GetBody()->SetLinearVelocity(b2Vec2(InputSystem::Axis().x * playerSpeed, 
  -InputSystem::Axis().y * playerSpeed));

  FlipSprite();
}
void Player::FlipSprite()
{
  sprite->setScale(InputSystem::Axis().x > 0 ? playerScale : InputSystem::Axis().x < 0 ? -playerScale : 
  sprite->getScale().x, 
  playerScale);
}