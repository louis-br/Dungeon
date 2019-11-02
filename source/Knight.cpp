#include"Knight.h"

void Knight::setAttack(int ATTACK){
  attack = ATTACK;
}

int Knight::getAttack(){
  return attack;
}

void Knight::setDefense(int DEFENSE){
  defense = DEFENSE;
}

int Knight::getDefense(){
  return defense;
}

void Knight::printMe(RenderWindow& WINDOW){
  WINDOW.draw(image);
}

void Knight::movement(){

}

void Knight::run(){

}

Knight::Knight()
{
  //image.setScale(0.1, 0.1);
  attack = 5;
  defense = 10;
}

Knight::~Knight(){
  attack = 0;
  defense = 0;
}
