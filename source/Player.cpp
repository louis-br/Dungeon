#include"Player.h"

bool Player::checkControls(){
  bool cond = false;
  if(Keyboard::isKeyPressed(Keyboard::Space)){
    jump = true;

    cond = true;
  }
  else if(Keyboard::isKeyPressed(Keyboard::Up)){
    cima = true;

    cond = true;
  }
  else if(Keyboard::isKeyPressed(Keyboard::Down)){
    lower = true;

    cond = true;
  }
  if(Keyboard::isKeyPressed(Keyboard::Left)){
    left = true;

    cond  = true;
  }
  else if(Keyboard::isKeyPressed(Keyboard::Right)){
    right = true;

    cond = true;
  }

  return cond;
}

void Player::restartControls(){
  left = false;
  right = false;
  lower = false;
  cima = false;
}

Player::Player():
Character()
{
  name = "player";
  left = false;
  right = false;
  jump = false;
  cima = false;
  lower = false;
  floor = false;
  collision = false;
  gravity = -10;
}

Player::~Player(){
  left = false;
  right = false;
  jump = false;
  lower = false;
  floor = false;
}
