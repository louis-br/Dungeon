#pragma once
#include"Enemy.h"
class Orc : public Enemy
{
public:
  int fury;
  int walkSize;

  void setNewAttackPower();
  void setNewVelocity();
  void movementControl();

  void collisionCharacter();
  void collisionBlock();
  void movement();
  void printMe(RenderWindow& window);
  void run();

  Orc(Type type, textureHolder& textures, TypeCharacter typeCharacter);
  ~Orc();
};
