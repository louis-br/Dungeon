#include"Block.h"

Textures::ID Block::toTextureID(Block::Type type){
  switch(type){
    case Block::brick:
      return Textures::brick;
      break;
    case Block::lava:
      return Textures::lava;
      break;
    case Block::ladder:
      return Textures::ladder;
      break;
  }
  return Textures::brick;
}

void Block::printMe(RenderWindow& window){
  window.draw(image);
}

void Block::run(){

}

Block::Block(Type type, textureHolder& textures):
blockType(type)
{
  image.setTexture(textures.getResource(toTextureID(type)));
  textures.getResource(toTextureID(type)).setRepeated(true);
}

Block::~Block(){

}
