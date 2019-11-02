#pragma once
#include"stdafx.h"

class Entity
{
protected:
  Vector2f position;
  FloatRect hitbox;
  Sprite image;
  Texture texture;

public:
  string name;
  void setPosition(Vector2f POSITION);
  Vector2f getPosition();
  void setImageAndTexture(string TEXTURE);
  void setImage();
  void setImageRect();
  void setImageRectAndTexture(string TEXTURE);
  void setTexture(string TEXTURE);
  Sprite getImage();
  FloatRect getHitBox();
  void setScale(float X, float Y);

  virtual void printMe(RenderWindow& WINDOW) = 0;
  virtual void run() = 0;

  Entity();
  ~Entity();
};
