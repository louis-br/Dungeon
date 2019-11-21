#include"Player.h"

void Player::handlePlayerInput(){
  if(Keyboard::isKeyPressed(Keyboard::Space)){
    setDirection(Vector2f(getDirection().x, -1));
    jump = true;
  }
  else if(Keyboard::isKeyPressed(Keyboard::S)){
    setDirection(Vector2f(getDirection().x, 1));
    lower = true;
  }

  if(Keyboard::isKeyPressed(Keyboard::D)){
    setDirection(Vector2f(1, getDirection().y));
    right = true;
  }

  else if(Keyboard::isKeyPressed(Keyboard::A)){
    setDirection(Vector2f(-1, getDirection().y));
    left = true;
  }
  if(Keyboard::isKeyPressed(Keyboard::O)){
    if(attacked)
      image.setPosition(image.getPosition().x, image.getPosition().y - 15);
    image.setTextureRect(IntRect(17, 437, 45, 80));
    attacked = false;
  }
  else{
    image.setTextureRect(IntRect(30, 7, 36, 65));
    attacked = true;
  }
}

Textures::ID Player::toTextureID(Player::Type type){
  switch(type){
    case Player::knight:
      return Textures::knight;
      break;
    case Player::mage:
      return Textures::mage;
      break;
  }
  return Textures::knight;
}

Player::Player(Type type, TypeCharacter typeCharacter):
playerType(type),
Character(typeCharacter)
{
}

Player::~Player(){

}
