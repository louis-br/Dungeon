#pragma once
#include"Entity.h"

class Block : public Entity
{
public:
  enum Type{
    brick,
    lava,
    ladder,
  };
protected:
  Type blockType;
public:
  Textures::ID toTextureID(Block::Type type);

  void printMe(RenderWindow& window);
  void run();

  Block(Type type, textureHolder& textures);
  ~Block();
};
