#pragma once
#include"Player.h"

class InputManager
{
public:
  void processEvents(RenderWindow& window, Player* player);

  InputManager();
  ~InputManager();
};
