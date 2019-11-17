#include"Game.h"

void Game::run(){
  Clock clock;
  Clock dead;
  Time timeLastSinceUpdate = Time::Zero;
  Time TimePerFrame = seconds(1.f/60.f);
  while(window.isOpen()){
    window.clear();
    if(jogador1->getLife() > 0){
      processEvents();

      auto aux = outOfCave->physicalManager.LCharacters.pFirst;
      while(aux){
        if(aux->pType->getLife() == 0 && aux->pType->TypeCharacter::player != aux->pType->characterType){
          outOfCave->physicalManager.LCharacters.popElement(aux->pType);
        }
        aux = aux->pNext;
      }

      timeLastSinceUpdate += clock.restart();
      while(timeLastSinceUpdate > TimePerFrame){
        timeLastSinceUpdate -= TimePerFrame;
        update(TimePerFrame);
      }
      render();
      dead.restart();

    }
    else if(jogador1->getLife() == 0 && dead.getElapsedTime().asSeconds() > 1.0f){
      processEvents();
      window.display();
    }
  }
}

void Game::update(Time deltaTime){
  outOfCave->run();
  outOfCave->physicalManager.checkCollision();
}

void Game::processEvents(){
  inputManager.processEvents(window, static_cast<Player*>(jogador1));
}

void Game::render(){
  outOfCave->printMe(window);
  window.setView(view);
  graphicManager.render(window);
}

Game::Game():
window(VideoMode(640, 480), "Dungeons++")
{
  outOfCave = new OutOfCave(outOfCave->Type::forest, graphicManager.textureMap);

  jogador1 = new Knight(jogador1->Type::knight, graphicManager.textureMap, jogador1->TypeCharacter::player);
  jogador1->image.setPosition(Vector2f(0, 300));
  jogador1->view = &view;
  jogador1->physicalManager = &(outOfCave->physicalManager);
  jogador1->setLife(3);
  jogador1->TH = &graphicManager.textureMap;

  view.setCenter(jogador1->getPosition().x, 300);
  view.setSize(640, 480);

  window.setView(view);

  Block* bc;
  bc = new Block(bc->Type::brick, graphicManager.textureMap);
  bc->image.setTextureRect(IntRect(0,0,2000, 36));
  bc->image.setPosition(Vector2f(-200, 446));
  bc->setPosition(bc->image.getPosition());

  Block* bc2;
  bc2 = new Block(bc2->Type::brick, graphicManager.textureMap);
  bc2->image.setTextureRect(IntRect(0,0, 36, 36));
  bc2->image.setPosition(Vector2f(300, 400));
  bc2->setPosition(bc2->image.getPosition());

  Block* bc3;
  bc3 = new Block(bc3->Type::brick, graphicManager.textureMap);
  bc3->image.setTextureRect(IntRect(0,0, 36, 36));
  bc3->image.setPosition(Vector2f(500, 400));
  bc3->setPosition(bc3->image.getPosition());

  Orc* orc1;
  orc1 = new Orc(orc1->Type::orc, graphicManager.textureMap, orc1->TypeCharacter::enemy);
  orc1->image.setPosition(Vector2f(400, 350));
  orc1->setPosition(orc1->image.getPosition());

  Spider* spider1;
  spider1 = new Spider(spider1->Type::spider, graphicManager.textureMap, spider1->TypeCharacter::enemy, 0);
  spider1->image.setPosition(Vector2f(200, 430));
  spider1->setPosition(spider1->image.getPosition());

  Stalactite* stalactite1;
  stalactite1 = new Stalactite(stalactite1->Type::stalactite, graphicManager.textureMap);
  stalactite1->image.setPosition(Vector2f(200, 100));
  stalactite1->setPosition(stalactite1->image.getPosition());

  outOfCave->physicalManager.LCharacters.pushElement(static_cast<Character*>(jogador1));
  outOfCave->physicalManager.LCharacters.pushElement(static_cast<Character*>(orc1));
  outOfCave->physicalManager.LCharacters.pushElement(static_cast<Character*>(spider1));

  outOfCave->physicalManager.LBlocks.pushElement(bc);
  outOfCave->physicalManager.LBlocks.pushElement(bc2);
  outOfCave->physicalManager.LBlocks.pushElement(bc3);

  outOfCave->physicalManager.LStalactite.pushElement(stalactite1);

  //outOfCave->LEntitys.pushEntity(static_cast<Entity*>(outOfCave));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(jogador1));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(bc));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(bc2));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(bc3));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(spider1));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(orc1));
  outOfCave->LEntitys.pushEntity(static_cast<Entity*>(stalactite1));
}

Game::~Game(){

}
