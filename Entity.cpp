#include"Entity.h"

void Entity::setPosition(Vector2f position){
  Entity::position = position;
}

Vector2f Entity::getPosition(){
  return position;
}

Entity::Entity(){
  setPosition(Vector2f(100, 100));
}

Entity::~Entity(){

}
