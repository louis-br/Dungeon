#include"Character.h"

void Character::setLife(int life){
  Character::life = life;
}

int Character::getLife(){
  return life;
}

void Character::setAttack(int attack){
  Character::attack = attack;
}

int Character::getAttack(){
  return attack;
}

void Character::setDefense(int defense){
  Character::defense = defense;
}

int Character::getDefense(){
  return defense;
}

Character::Character(TypeCharacter type):
attacked(false),
characterType(type),
collisionOn(true)
{

}

Character::~Character(){

}
