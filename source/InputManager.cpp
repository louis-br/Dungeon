#include"InputManager.h"

void InputManager::processEvents(RenderWindow& window, Player* player){
  Event event;

  while(window.pollEvent(event)){
    switch (event.type) {
      case Event::Closed:
        window.close();
        break;
    }
  }
}

InputManager::InputManager(){

}

InputManager::~InputManager(){

}
