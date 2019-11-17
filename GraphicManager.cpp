#include"GraphicManager.h"

void GraphicManager::loadTextures(){
  loadTexture(Textures::brick, "data/images/Plataforma2.png");
  loadTexture(Textures::knight, "data/images/Anaos.png");
  loadTexture(Textures::orc, "data/images/Inimigo1.png");
  loadTexture(Textures::spider, "data/images/spider.png");
  loadTexture(Textures::forest, "data/images/Fundo1.png");
  loadTexture(Textures::stalactite, "data/images/stalactite4.png");
}

void GraphicManager::loadTexture(Textures::ID id, string filename){
  textureMap.loadResource(id, filename);
}

Texture& GraphicManager::getTexture(Textures::ID id){
  return textureMap.getResource(id);
}

void GraphicManager::render(RenderWindow& window){
  window.display();
}

GraphicManager::GraphicManager(){
  loadTextures();
}

GraphicManager::~GraphicManager(){

}
