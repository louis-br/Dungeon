#pragma once
#include"Player.h"

class Knight : public Player
{
private:
  int attack;
  int defense;
public:
  void setAttack(int ATTACK);
  int getAttack();
  void setDefense(int DEFENSE);
  int getDefense();

  void printMe(RenderWindow& WINDOW);
  void movement();
  void run();

  Knight();
  ~Knight();
};
