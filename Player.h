#pragma once
#include"Character.h"

class Player : public Character
{
public:
  enum Type{
    knight,
    mage,
  };
protected:
  Type playerType;
public:
  void handlePlayerInput();
  Textures::ID toTextureID(Player::Type type);

  virtual void collisionCharacter(){}
  virtual void collisionBlock(){}
  virtual void movement(){}
  virtual void printMe(RenderWindow& window){}
  virtual void run(){}

  Player(Type type, TypeCharacter typeCharacter);
  ~Player();
};
