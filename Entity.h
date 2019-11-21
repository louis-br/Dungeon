#pragma once
#include"stdafx.h"
#include"ResourceHolder.h"

namespace Textures{
  enum ID{
    brick,
    lava,
    ladder,
    knight,
    mage,
    orc,
    spider,
    forest,
    cave,
    spiderWeb,
    stalactite,
  };
}

typedef ResourceHolder<Texture, Textures::ID> textureHolder;

class Entity
{
protected:
  Vector2f position;
public:
  Sprite image;
  textureHolder* TH;

  void setPosition(Vector2f position);
  Vector2f getPosition();
  virtual void printMe(RenderWindow& window) = 0;
  virtual void run() = 0;

  Entity();
  ~Entity();
};
