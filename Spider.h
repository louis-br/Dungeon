#pragma once
#include"Enemy.h"

class Spider : public Enemy
{
public:
  int descentSize;
  int walkSize;
  int form;

  void collisionCharacter();
  void collisionBlock();
  void movementControl();
  void movement();
  void printMe(RenderWindow& window);
  void run();

  Spider(Type type, textureHolder& textures, TypeCharacter typeCharacter, int form);
  ~Spider();
};
