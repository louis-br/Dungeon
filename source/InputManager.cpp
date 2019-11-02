#include"InputManager.h"

bool InputManager::movement(Player* PLAYER, EntityList& LE, CollisionManager& COLLIDER, View& VIEW){
  bool collision = false;
  PLAYER->checkControls();
  if(PLAYER->jump){
    if(PLAYER->left){
      PLAYER->setPosition(Vector2f(PLAYER->getPosition().x - 2, PLAYER->getPosition().y + PLAYER->gravity));
      VIEW.move(-2, 0);
    }
    else if(PLAYER->right){
      PLAYER->setPosition(Vector2f(PLAYER->getPosition().x + 2, PLAYER->getPosition().y + PLAYER->gravity));
      VIEW.move(2, 0);
    }
    else{
      PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y + PLAYER->gravity));
    }
    PLAYER->gravity += 0.5;
    auto aux = LE.LEs.pFirst->pNext;

    while(aux){
      if(COLLIDER.collision(static_cast<Entity*>(PLAYER), aux->pType)){
        PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y - PLAYER->gravity + 0.5));
        collision = true;
        PLAYER->jump = false;
        PLAYER->gravity = -10;
        break;
      }
      aux = aux->pNext;
    }

  }
  else if(PLAYER->lower){
    PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y + 2));
  }
  else if(PLAYER->cima){
    PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y - 2));
  }
  else if(PLAYER->left){
    VIEW.move(-2, 0);
    PLAYER->setPosition(Vector2f(PLAYER->getPosition().x - 2, PLAYER->getPosition().y));
  }
  else if(PLAYER->right){
    VIEW.move(2, 0);
    PLAYER->setPosition(Vector2f(PLAYER->getPosition().x + 2, PLAYER->getPosition().y));
  }

  auto aux3 = LE.LEs.pFirst->pNext;

  while(aux3){
    if(COLLIDER.collision(static_cast<Entity*>(PLAYER), aux3->pType)){
      if(PLAYER->lower){
        collision = true;
        PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y - 2));
      }
      else if(PLAYER->cima){
        collision = true;
        PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y + 2));
      }
      else if(PLAYER->left){
        VIEW.move(2, 0);
        collision = true;
        PLAYER->setPosition(Vector2f(PLAYER->getPosition().x + 2, PLAYER->getPosition().y));
      }
      else if(PLAYER->right){
        VIEW.move(-2, 0);
        collision = true;
        PLAYER->setPosition(Vector2f(PLAYER->getPosition().x - 2, PLAYER->getPosition().y));
      }
      break;
    }
    aux3 = aux3->pNext;
  }
  int i;
  float erro = 10;
  auto aux4 = LE.LEs.pFirst->pNext;
  if(!PLAYER->jump){
    for(i = 0; i < 2; i++){
      PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y + erro));
      /*if(erro != 10)
        VIEW.move(0, erro);*/
      while(aux4){
        if(COLLIDER.collision(static_cast<Entity*>(PLAYER), aux4->pType)){
          /*if(erro != 10)
            VIEW.move(0, -erro);*/
          PLAYER->setPosition(Vector2f(PLAYER->getPosition().x, PLAYER->getPosition().y - erro));
          break;
        }
        aux4 = aux4->pNext;
      }
      erro -= 9.5;
    }
  }

  PLAYER->restartControls();

  return collision;
}

InputManager::InputManager(){

}

InputManager::~InputManager(){

}
