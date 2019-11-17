#pragma once
#include"InputManager.h"
#include"GraphicManager.h"
#include"Knight.h"
#include"OutOfCave.h"
#include"Orc.h"
#include"Spider.h"
#include"Stalactite.h"

class Game
{
private:
  OutOfCave *outOfCave;
  Knight* jogador1;

  RenderWindow window;
  View view;

  InputManager inputManager;
  GraphicManager graphicManager;
public:
  void run();
  void update(Time deltaTime);
  void processEvents();
  void render();

  Game();
  ~Game();
};
