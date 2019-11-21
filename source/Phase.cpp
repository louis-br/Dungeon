#include"Phase.h"

Textures::ID Phase::toTextureID(Phase::Type type){
  switch(type){
    case Phase::forest:
      return Textures::forest;
      break;
    case Phase::cave:
      return Textures::cave;
      break;
  }
  return Textures::knight;
}

Phase::Phase(Type type):
phaseType(type)
{
}

Phase::~Phase(){

}
