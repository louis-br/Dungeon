#pragma once
#include"List.h"
#include"Entity.h"

class EntityList{
public:
  List<Entity*> LEs;

  void pushEntity(Entity* ENTITY);
  void popEntity(Entity& ENTITY);
  void clear();
  EntityList();
  ~EntityList();
};
