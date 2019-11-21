#include"Stalactite.h"

void Stalactite::collisionBlock(){

}

void Stalactite::movementControl(bool moviment){
  lower = moviment;
}

void Stalactite::movement(){
  Vector2f m = Vector2f(0.f,0.f);

  if(lower){
    m.y += getVelocity().y;
  }
  image.move(m);
  setPosition(image.getPosition());
}

void Stalactite::printMe(RenderWindow& window){
  window.draw(image);
}

void Stalactite::run(){
  movement();
}

Stalactite::Stalactite(Type type, textureHolder& textures):
Obstacle(type),
falling(false)
{
  lower = false;
  setVelocity(Vector2f(4.f, 4.f));

  image.setTexture(textures.getResource(toTextureID(type)));
}

Stalactite::~Stalactite(){

}
