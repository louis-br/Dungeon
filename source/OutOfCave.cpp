#include"OutOfCave.h"

void OutOfCave::printMe(RenderWindow& window){
  window.draw(image);
  auto aux = LEntitys.LEs.pFirst;

  while(aux){
    aux->pType->printMe(window);

    aux = aux->pNext;
  }
}

void OutOfCave::run(){
  auto aux = LEntitys.LEs.pFirst;

  while(aux){
    aux->pType->run();

    aux = aux->pNext;
  }
}

OutOfCave::OutOfCave(Type type, textureHolder& textures):
Phase(type)
{
  image.setTexture(textures.getResource(toTextureID(type)));
  textures.getResource(toTextureID(type)).setRepeated(true);
  image.setPosition(-200, 5);
  setPosition(image.getPosition());
  image.setTextureRect(IntRect(0,0,6000, 480));
}

OutOfCave::~OutOfCave(){

}
