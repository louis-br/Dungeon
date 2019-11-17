#include"Orc.h"

void Orc::collisionCharacter(){
  fury++;
  if(attacked && collisionOn){
    setLife(getLife() - 1);
    attacked = false;
    collisionOn = false;
  }
}

void Orc::setNewAttackPower(){
  if(fury == 2 || fury == 3){
    setAttack(getAttack()*(1 + fury/5));
  }
}

void Orc::setNewVelocity(){
  if(fury == 1){
    setVelocity(Vector2f(4, getVelocity().y));
  }
}

void Orc::movementControl(){
  if(left && walkSize == 80){
    left = false;
    right = true;
    walkSize = 0;
  }
  else if(right && walkSize == 80){
    left = true;
    right = false;
    walkSize = 0;
  }
}

void Orc::collisionBlock(){
  Vector2f m = Vector2f(0.f,0.f);
  if(left){
    left = false;
    right = true;
    walkSize = 0;
    m.x += getVelocity().x;
    image.move(m);
    setPosition(image.getPosition());
  }
  else if(right){
    right = false;
    left = true;
    walkSize = 0;
    m.x -= getVelocity().x;
    image.move(m);
    setPosition(image.getPosition());
  }
}

void Orc::movement(){
  if(clock.getElapsedTime().asSeconds() > 4.0f){
    clock.restart();
    collisionOn = true;
  }
  movementControl();
  Vector2f m = Vector2f(0.f,0.f);
  if(left){
    m.x -= getVelocity().x;
    walkSize++;
  }
  else if(right){
    m.x += getVelocity().x;
    walkSize++;
  }
  image.move(m);
  setPosition(image.getPosition());
}

void Orc::printMe(RenderWindow& window){
  if(getLife() > 0)
    window.draw(image);
}

void Orc::run(){
  movement();
  setNewAttackPower();
  setNewVelocity();
}



Orc::Orc(Type type, textureHolder& textures, TypeCharacter typeCharacter):
Enemy(type, typeCharacter),
fury(0),
walkSize(0)
{
  setLife(2);
  left = true;
  setAttack(2);
  setDefense(15);
  setVelocity(Vector2f(2.f,2.f));
  image.setScale(3.f, 3.f);
  image.setTexture(textures.getResource(toTextureID(type)));
}

Orc::~Orc(){

}
