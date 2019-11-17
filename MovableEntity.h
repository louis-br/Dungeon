#pragma once
#include"Entity.h"
#include"PhysicalManager.h"

class MovableEntity : public Entity
{
protected:
  Vector2f direction;
  Vector2f velocity;
  Vector2f maxVelocity;
  Vector2f aceleration;
public:
  bool jumpOn;
  bool floor;
  bool left;
  bool right;
  bool jump;
  bool lower;
  PhysicalManager* physicalManager;

  void setDirection(Vector2f direction);
  Vector2f getDirection();
  void setVelocity(Vector2f velocity);
  Vector2f getVelocity();
  void setMaxVelocity(Vector2f maxVelocity);
  Vector2f getMaxVelocity();
  void setAceleration(Vector2f aceleration);
  Vector2f getAceleration();

  virtual void collisionBlock() = 0;
  virtual void movement() = 0;
  virtual void printMe(RenderWindow& window) = 0;
  virtual void run() = 0;

  MovableEntity();
  ~MovableEntity();
};
