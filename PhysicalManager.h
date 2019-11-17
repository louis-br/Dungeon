#pragma once
#include"List.h"
#include"Block.h"

class Stalactite;
class Character;
class PhysicalManager
{
public:
  float gravity;
  
  List<Character*> LCharacters;
  List<Block*> LBlocks;
  List<Stalactite*> LStalactite;

  bool checkCollision();

  PhysicalManager();
  ~PhysicalManager();
};
