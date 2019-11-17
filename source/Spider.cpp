#include"Spider.h"

void Spider::collisionCharacter(){
  if(attacked && collisionOn){
    setLife(getLife() - 1);
    attacked = false;
    collisionOn = false;
  }
}

void Spider::collisionBlock(){}

void Spider::movement(){
  if(clock.getElapsedTime().asSeconds() > 4.0f){
    clock.restart();
    collisionOn = true;
  }
  movementControl();
  Vector2f m = Vector2f(0.f,0.f);
  if(form == 1){
    if(jump){
      m.y -= getVelocity().y;
      descentSize++;
    }
    else if(lower){
      m.y += getVelocity().y;
      descentSize++;
    }
  }
  if(form == 0){
    if(left){
      m.x -= getVelocity().y;
      walkSize++;
    }
    else if(right){
      m.x += getVelocity().y;
      walkSize++;
    }
  }

  image.move(m);
  setPosition(image.getPosition());
}

void Spider::movementControl(){
  if(form == 1){
    if(lower && descentSize == 60){
      setVelocity(Vector2f(2.f, 2.f));
      lower = false;
      jump = true;
      descentSize = 0;
    }
    else if(jump && descentSize == 60){
      setVelocity(Vector2f(2.f, 2.f));
      lower = true;
      jump = false;
      descentSize = 0;
    }
  }

  if(form == 0){
    if(right && walkSize == 60){
      setVelocity(Vector2f(2.f, 2.f));
      right = false;
      left = true;
      walkSize = 0;
    }
    else if(left && walkSize == 60){
      setVelocity(Vector2f(2.f, 2.f));
      right = true;
      left = false;
      walkSize = 0;
    }
  }
}

void Spider::printMe(RenderWindow& window){
  if(getLife() > 0)
    window.draw(image);
}

void Spider::run(){
  movement();
}

Spider::Spider(Type type, textureHolder& textures, TypeCharacter typeCharacter, int form):
Enemy(type, typeCharacter),
descentSize(0),
walkSize(0)
{
  Spider::form = form;
  if(form == 1){
    lower = true;
  }
  else if(form == 0){
    left = true;
  }
  setLife(1);
  setVelocity(Vector2f(2.f, 2.f));
  image.setTexture(textures.getResource(toTextureID(type)));
  image.setScale(2.3f, 2.3f);
}

Spider::~Spider(){

}
