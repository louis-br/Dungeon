#include"MovableEntity.h"

void MovableEntity::setDirection(Vector2f direction){
  MovableEntity::direction = direction;
}

Vector2f MovableEntity::getDirection(){
  return direction;
}

void MovableEntity::setVelocity(Vector2f velocity){
  MovableEntity::velocity = velocity;
}

Vector2f MovableEntity::getVelocity(){
  return velocity;
}

void MovableEntity::setMaxVelocity(Vector2f maxVelocity){
  MovableEntity::maxVelocity = maxVelocity;
}

Vector2f MovableEntity::getMaxVelocity(){
  return maxVelocity;
}

void MovableEntity::setAceleration(Vector2f aceleration){
  MovableEntity::aceleration = aceleration;
}

Vector2f MovableEntity::getAceleration(){
  return aceleration;
}

MovableEntity::MovableEntity():
jumpOn(true),
floor(false),
left(false),
right(false),
jump(false),
lower(false)
{

}

MovableEntity::~MovableEntity(){

}
