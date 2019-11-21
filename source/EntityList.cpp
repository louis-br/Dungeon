#include"EntityList.h"

void EntityList::pushEntity(Entity* ENTITY){
  LEs.pushElement(ENTITY);
}

void EntityList::popEntity(Entity& ENTITY){
  //LEs.popElement(ENTITY);
}

void EntityList::clear(){
  List<Entity*>::Element* aux ,* aux2;
  aux = LEs.pFirst;
  while(aux){
    aux2 = aux;
    delete aux;
    aux = aux2->pPrevious;
  }
}

EntityList::EntityList(){}

EntityList::~EntityList(){}
