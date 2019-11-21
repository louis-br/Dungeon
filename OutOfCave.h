#include"Phase.h"
#include"Block.h"

class OutOfCave : public Phase
{
public:
  void printMe(RenderWindow& window);
  void run();

  OutOfCave(Type type, textureHolder& textures);
  ~OutOfCave();
};
