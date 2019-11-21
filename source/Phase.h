#pragma once
#include"EntityList.h"
#include"PhysicalManager.h"

class Phase : public Entity
{
public:
  enum Type{
    forest,
    cave,
  };
protected:
  Type phaseType;
public:
  Textures::ID toTextureID(Phase::Type type);

  EntityList LEntitys;
  PhysicalManager physicalManager;

  virtual void printMe(){}
  virtual void run(){}

  Phase(Type type);
  ~Phase();
};
