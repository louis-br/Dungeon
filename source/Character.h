#pragma once
#include"Entity.h"

class Character : public Entity
{
protected:
  int life;
  float velocity;
  float aceleration;
  Vector2f direction;

public:
  void setLife(int LIFE);
  int getLife();
  void setVelocity(float VELOCITY);
  float getVelocity();
  void setAceleration(float ACELERATION);
  float getAceleration();
  void setDirection(Vector2f DIRECTION);
  Vector2f getDiretion();

  virtual void movement() = 0;
  virtual void printMe(RenderWindow& WINDOW) = 0;
  virtual void run() = 0;

  Character();
  ~Character();
};
