#include"Enemy.h"

Textures::ID Enemy::toTextureID(Enemy::Type type){
  switch(type){
    case Enemy::orc:
      return Textures::orc;
      break;
    case Enemy::spider:
      return Textures::spider;
      break;
  }
  return Textures::orc;
}

Enemy::Enemy(Type type, TypeCharacter typeCharacter):
enemyType(type),
Character(typeCharacter)
{
}

Enemy::~Enemy(){

}
