#include"Entity.h"

void Entity::setPosition(Vector2f POSITION){
  position = POSITION;
  image.setPosition(POSITION);
}

Vector2f Entity::getPosition(){
  return position;
}

void Entity::setImageAndTexture(string TEXTURE){
  setTexture(TEXTURE);
  setImage();
}

void Entity::setImage(){
  image.setTexture(texture);
}
void Entity::setImageRect(){
  image.setTexture(texture);
  image.setTextureRect(IntRect(1, 1, 45, 63));
}

void Entity::setImageRectAndTexture(string TEXTURE){
  setTexture(TEXTURE);
  setImageRect();
}

void Entity::setTexture(string TEXTURE){
  texture.loadFromFile(TEXTURE);
}

Sprite Entity::getImage(){
  return image;
}

FloatRect Entity::getHitBox(){
  return hitbox;
}

void Entity::setScale(float X, float Y){
  image.setScale(X, Y);
}

Entity::Entity(){
  hitbox = image.getGlobalBounds();
}

Entity::~Entity(){

}
