#pragma once
#include"EntityList.h"
#include"CollisionManager.h"
#include"InputManager.h"
#include"GrassBlock.h"

class Knight;
class Phase : public Entity
{
public:
  Knight* K;
  CollisionManager collider;
  InputManager input;
  EntityList LEntitys;
  void printMe(RenderWindow& WINDOW);
  void run();

  Phase();
  ~Phase();
};
