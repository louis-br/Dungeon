#include"PhysicalManager.h"
#include"Character.h"
#include"Stalactite.h"

bool PhysicalManager::checkCollision(){
  bool collision = false;
  auto C1 = LCharacters.pFirst;
  auto C2 = LCharacters.pFirst->pNext;
  auto E1 = LStalactite.pFirst;

  while(E1){
    auto e = E1->pType->image.getGlobalBounds();
    e.height = 2000;
    e.left = e.left + 40;
    if(C1->pType->image.getGlobalBounds().intersects(e)){
      E1->pType->movementControl(true);
      E1->pType->run();
      e.height = E1->pType->image.getGlobalBounds().height;
      e.left = e.left + 40;
      if(C1->pType->image.getGlobalBounds().intersects(e)){
        C1->pType->attacked = true;
        C1->pType->collisionCharacter();
      }
    }
    E1 = E1->pNext;
  }

  while(C1){
    bool collisionBlock = false;
    bool collisionBlockTop = false;
    auto a = C1->pType->image.getGlobalBounds();
    auto b = C1->pType->image.getGlobalBounds();
    a.top += 1;
    b.top -=1;
    auto B = LBlocks.pFirst;
    while(B){
      if(C1->pType->image.getGlobalBounds().intersects(B->pType->image.getGlobalBounds())){
        C1->pType->floor = true;
        collision = true;
        collisionBlock = true;
        int D = (C1->pType->getPosition().y + C1->pType->image.getGlobalBounds().height) - B->pType->getPosition().y;
        if(C1->pType->getDirection().y != 0 && (B->pType->getPosition().y + B->pType->image.getGlobalBounds().height) >= (C1->pType->getPosition().y + C1->pType->image.getGlobalBounds().height)){
          C1->pType->image.move(Vector2f(0, -D));
          C1->pType->setDirection(Vector2f(0,0));
        }
        else if(C1->pType->getDirection().y != 0 && (B->pType->getPosition().y + B->pType->image.getGlobalBounds().height) <= (C1->pType->getPosition().y + C1->pType->image.getGlobalBounds().height)){
          collisionBlockTop = true;
          C1->pType->floor = false;
          C1->pType->image.move(Vector2f(0, -gravity));
          C1->pType->setDirection(Vector2f(0,0));
        }
        C1->pType->collisionBlock();
      }
      else{
        if(a.intersects(B->pType->image.getGlobalBounds())){
          collisionBlock = true;
        }
        if(b.intersects(B->pType->image.getGlobalBounds())){
          collisionBlockTop = true;
        }
      }
      while(C2){
        if(C2 && C2->pType->getLife() > 0 && C1->pType->image.getGlobalBounds().intersects(C2->pType->image.getGlobalBounds())){
          if(C1->pType->TypeCharacter::player == C1->pType->characterType && C2->pType->TypeCharacter::enemy == C2->pType->characterType || C2->pType->TypeCharacter::player == C2->pType->characterType && C1->pType->TypeCharacter::enemy == C1->pType->characterType){
            if(C1->pType->collisionOn && C2->pType->collisionOn){
              if(C1->pType->TypeCharacter::player == C1->pType->characterType && !C1->pType->attacked){
                C2->pType->attacked = true;
              }
              else if(C2->pType->TypeCharacter::player == C2->pType->characterType && !C2->pType->attacked){
                C1->pType->attacked = true;
              }
              C1->pType->collisionCharacter();
              C2->pType->collisionCharacter();
            }
            C1->pType->attacked = false;
            C2->pType->attacked = false;
          }
          collision = true;
        }
        C2 = C2->pNext;
      }
      B = B->pNext;
    }
    if(collisionBlockTop){
      C1->pType->jumpOn = false;
    }
    if(!collisionBlock){
      C1->pType->floor = false;
    }
    if(collisionBlock && !collisionBlockTop){
      C1->pType->jumpOn = true;
    }
    C1 = C1->pNext;
    if(C2)
      C2 = C1->pNext;
  }
  return collision;
}

PhysicalManager::PhysicalManager():
gravity(-15)
{
}

PhysicalManager::~PhysicalManager(){

}
