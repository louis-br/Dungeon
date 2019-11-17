#include"GrassBlock.h"

float GrassBlock::getWeight(){
  return weight;
}

float GrassBlock::getFriction(){
  return friction;
}

void GrassBlock::printMe(RenderWindow& WINDOW){
  WINDOW.draw(image);
}

void GrassBlock::run(){

}

GrassBlock::GrassBlock(int ID, float WEIGHT, float FRICTION):
Block(ID)
{
  name = "grassBlock";
  weight = WEIGHT;
  friction = FRICTION;
}

GrassBlock::~GrassBlock(){

}
