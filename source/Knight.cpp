#include"Knight.h"

void Knight::collisionCharacter(){
  if(attacked && collisionOn){
    cout << "Entrou." << endl;
    image.setPosition(image.getPosition().x, image.getPosition().y - 15);
    image.setTextureRect(IntRect(17, 437, 45, 80));
    setLife(getLife() - 1);
    attacked = false;
    collisionOn = false;
    clock.restart();
  }
}

void Knight::collisionBlock(){
  Vector2f m = Vector2f(0.f,0.f);
  if(left){
    left = false;
    m.x += getVelocity().x;
    view->move(getVelocity().x, 0);
    image.move(m);
    setPosition(image.getPosition());
  }
  else if(right){
    right = false;
    m.x -= getVelocity().x;
    view->move(-getVelocity().x, 0);
    image.move(m);
    setPosition(image.getPosition());
  }
  if(jump){
    jump = false;
    physicalManager->gravity = -15;
    image.move(m);
    setPosition(image.getPosition());
  }
}

void Knight::movement(){
  Vector2f m = Vector2f(0.f,0.f);
  lower = false;
  right = false;
  left = false;
  handlePlayerInput();

  if(!collisionOn && clock.getElapsedTime().asSeconds() < 0.5f){
    if(clock.getElapsedTime().asSeconds() / 0.1 == 0){
      image.setTextureRect(IntRect(17, 437, 45, 80));
    }
    else{
      image.setTextureRect(IntRect(30, 7, 36, 65));
    }
  }
  if(clock.getElapsedTime().asSeconds() > 1.f){
    clock.restart();
    collisionOn = true;
  }
  if(!floor && !jump || !floor && !jumpOn){
    int a = 0;
    setDirection(Vector2f(getDirection().x, 1));
    m.y += 7;
    if(right){
      m.x += getVelocity().x;
    }
    else if(left){
      m.x -= getVelocity().x;
    }
    a++;
  }
  else if(jump && jumpOn){
    if(right){
      m.y += physicalManager->gravity;
      m.x += getVelocity().x/2;
    }
    else if(left){
      m.y += physicalManager->gravity;
      m.x -= getVelocity().x/2;
    }
    else{
        m.y += physicalManager->gravity;
    }
    physicalManager->gravity += 1;
  }
  else if(lower){
    m.y += getVelocity().y;
  }
  if(right){
    m.x += getVelocity().x;
  }
  else if(left){
    m.x -= getVelocity().x;
  }

  image.move(m);
  setPosition(image.getPosition());
  view->setCenter(getPosition().x + 120, 245);
}

void Knight::printMe(RenderWindow& window){
  window.draw(image);
}

void Knight::run(){
  movement();
}

Knight::Knight(Type type, textureHolder& textures, TypeCharacter typeCharacter):
Player(type, typeCharacter)
{
  attacked = true;
  setAttack(7);
  setDefense(10);
  setVelocity(Vector2f(6.f,6.f));
  //image.setScale(Vector2f(0.15f, 0.15f));
  image.setTexture(textures.getResource(toTextureID(type)));
  image.setTextureRect(IntRect(30, 7, 36, 65));
}

Knight::~Knight(){

}
