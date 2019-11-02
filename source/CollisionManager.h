#pragma once
#include"Entity.h"

class CollisionManager
{
public:
  bool collision(Entity* A, Entity* B);
  CollisionManager();
  ~CollisionManager();
};
