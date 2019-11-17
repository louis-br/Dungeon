#pragma once
#include"Block.h"

class GrassBlock : public Block
{
private:
  float weight;
  float friction;

public:
  float getWeight();
  float getFriction();

  void printMe(RenderWindow& WINDOW);
  void run();

  GrassBlock(int ID = GRASS, float WEIGHT = 50.0, float FRICTION = 4.0);
  ~GrassBlock();
};
