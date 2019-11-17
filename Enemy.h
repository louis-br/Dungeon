#pragma once
#include"Character.h"

class Enemy : public Character
{
public:
  enum Type{
    orc,
    spider,
  };
protected:
  Type enemyType;
public:
  Textures::ID toTextureID(Enemy::Type type);

  virtual void collisionCharacter(){}
  virtual void collisionBlock(){}
  virtual void movement(){}
  virtual void printfMe(RenderWindow& window){}
  virtual void run(){}

  Enemy(Type type, TypeCharacter typeCharacter);
  ~Enemy();
};
