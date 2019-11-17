#pragma once
#include"Player.h"
#include"CollisionManager.h"
#include"EntityList.h"

class InputManager
{
public:
  bool movement(Player* PLAYER, EntityList& LE, CollisionManager& COLLIDER, View& VIEW);
  InputManager();
  ~InputManager();
};
