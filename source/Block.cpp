#include"Block.h"

void Block::setMovable(bool MOVABLE){
  movable = MOVABLE;
}

bool Block::getMovable(){
  return movable;
}

Block::Block(int ID):
Entity()
{
  if(ID <= 2){
    setMovable(false);
  }
  else{
    setMovable(true);
  }
}

Block::~Block(){

}
