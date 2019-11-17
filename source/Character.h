#pragma once
#include"MovableEntity.h"

class Character : public MovableEntity
{
protected:
  int life;
  int attack;
  int defense;
public:
  enum TypeCharacter{
    enemy,
    player,
  };
  TypeCharacter characterType;

  Clock clock;
  bool collisionOn;
  bool attacked;

  void setLife(int life);
  int getLife();
  void setAttack(int attack);
  int getAttack();
  void setDefense(int defense);
  int getDefense();

  virtual void collisionCharacter() = 0;
  virtual void collisionBlock() = 0;
  virtual void movement() = 0;
  virtual void printMe(RenderWindow& window) = 0;
  virtual void run() = 0;

  Character(TypeCharacter type);
  ~Character();
};
