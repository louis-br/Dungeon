#pragma once
#include"Entity.h"

class Block : public Entity
{
protected:
  int id;
  bool movable;

public:
  void setMovable(bool MOVABLE);
  bool getMovable();

  enum{BRICKS = 1, GRASS = 2};

  virtual void printMe(RenderWindow& WINDOW) = 0;
  virtual void run() = 0;

  Block(int ID);
  ~Block();
};
