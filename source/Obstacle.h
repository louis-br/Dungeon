#pragma once
#include"stdafx.h"
#include"Entity.h"

class Obstacle
{
public:
  enum Type{
    spiderWeb,
    stalactite,
  };
protected:
  Type obstacleType;
public:
  Textures::ID toTextureID(Obstacle::Type type);
  virtual void movement() = 0;
  virtual void printMe(RenderWindow& window) = 0;
  virtual void run() = 0;

  Obstacle(Type type);
  ~Obstacle();
};
