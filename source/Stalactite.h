#pragma once
#include"MovableEntity.h"
#include"Obstacle.h"

class Stalactite : public Obstacle, public MovableEntity
{
public:
  bool falling;

  void collisionBlock();
  void movementControl(bool moviment);
  void movement();
  void printMe(RenderWindow& window);
  void run();

  Stalactite(Type type, textureHolder& textures);
  ~Stalactite();
};
