#pragma once
#include"Entity.h"
#include"ResourceHolder.h"

class GraphicManager
{
public:
  textureHolder textureMap;

  void loadTextures();
  void loadTexture(Textures::ID, string filename);
  Texture& getTexture(Textures::ID);
  void render(RenderWindow& window);

  GraphicManager();
  ~GraphicManager();
};
