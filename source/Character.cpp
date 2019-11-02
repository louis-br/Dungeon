#include"Character.h"

void Character::setLife(int LIFE){
  life = LIFE;
}

int Character::getLife(){
  return life;
}

void Character::setVelocity(float VELOCITY){
  velocity = VELOCITY;
}

float Character::getVelocity(){
  return velocity;
}

void Character::setAceleration(float ACELERATION){
  aceleration = ACELERATION;
}

float Character::getAceleration(){
  return aceleration;
}

void Character::setDirection(Vector2f DIRECTION){
  direction = DIRECTION;
}

Vector2f Character::getDiretion(){
  return direction;
}

Character::Character():
Entity()
{
  velocity = 0;
  direction = Vector2f(0,0);
  aceleration = 0;
}

Character::~Character(){
  velocity = 0;
  direction = Vector2f(0,0);
  aceleration = 0;
}
