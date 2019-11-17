#pragma once
#include"Character.h"
#include"CollisionManager.h"

class Player : public Character
{
public:
  bool right;
  bool left;
  bool jump;
  bool lower;
  bool floor;
  bool cima;
  bool collision;
  float gravity;

  bool checkControls();
  void restartControls();

  virtual void movement(){}
  virtual void printMe(RenderWindow WINDOW){}
  virtual void run(){}

  Player();
  ~Player();
};
