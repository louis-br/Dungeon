#include"Obstacle.h"

Textures::ID Obstacle::toTextureID(Obstacle::Type type){
  switch(type){
    case Obstacle::spiderWeb:
      return Textures::spiderWeb;
      break;
    case Obstacle::stalactite:
      return Textures::stalactite;
      break;
  }
  return Textures::knight;
}

Obstacle::Obstacle(Type type):
obstacleType(type)
{

}

Obstacle::~Obstacle(){

}
