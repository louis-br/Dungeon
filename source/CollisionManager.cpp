#include"CollisionManager.h"

bool CollisionManager::collision(Entity* A, Entity* B){
  FloatRect aux, aux2;
  aux = FloatRect(A->getImage().getPosition().x, A->getImage().getPosition().y, A->getImage().getGlobalBounds().width, A->getImage().getGlobalBounds().height);
  aux2 = FloatRect(B->getImage().getPosition().x, B->getImage().getPosition().y, B->getImage().getGlobalBounds().width, B->getImage().getGlobalBounds().height);
  if(aux.intersects(aux2)){
    return true;
  }
  return false;
}

CollisionManager::CollisionManager(){

}

CollisionManager::~CollisionManager(){

};
