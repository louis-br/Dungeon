#pragma once
#include"Player.h"

class Knight : public Player
{
public:
  View* view;

  void collisionCharacter();
  void collisionBlock();
  void movement();
  void printMe(RenderWindow& window);
  void run();

  Knight(Type type, textureHolder& textures, TypeCharacter typeCharacter);
  ~Knight();
};
