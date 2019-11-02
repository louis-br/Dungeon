#include"Phase.h"
#include"Knight.h"

void Phase::printMe(RenderWindow& WINDOW){

}

void Phase::run(){
  View view(FloatRect(0,0, 500, 450));
  RenderWindow window(VideoMode(700, 450), "Dungeons++");

  window.setView(view);

  view.setCenter(350, 225);
  Event event;
  Clock clock;

  while(window.isOpen()){
    while(window.pollEvent(event)){
      if(event.type == Event::Closed){
        window.close();
      }
    }

    window.clear(Color::Black);

    if(clock.getElapsedTime().asSeconds() > 0.01f){

      clock.restart();

      window.draw(getImage());
      auto aux = LEntitys.LEs.pFirst;

      while(aux){
        aux->pType->printMe(window);
        aux = aux->pNext;
      }
      input.movement(K, LEntitys, collider, view);
      window.setView(view);
      window.display();
    }
  }
}

Phase::Phase():
Entity()
{
  setImageAndTexture("data/imagens/fase.jpg");

  K = new Knight();
  K->setImageAndTexture("data/imagens/10.png") ;
  K->setPosition(Vector2f(200, 0));

  GrassBlock* GB1 = new GrassBlock();
  GB1->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB1->setPosition(Vector2f(250, 370));

  GrassBlock* GB2 = new GrassBlock();
  GB2->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB2->setPosition(Vector2f(325, 340));

  GrassBlock* GB3 = new GrassBlock();
  GB3->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB3->setPosition(Vector2f(400, 310));

  GrassBlock* GB4 = new GrassBlock();
  GB4->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB4->setPosition(Vector2f(475, 280));

  GrassBlock* GB9 = new GrassBlock();
  GB9->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB9->setPosition(Vector2f(550, 250));

  GrassBlock* GB5 = new GrassBlock();
  GB5->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB5->setPosition(Vector2f(0, 410));

  GrassBlock* GB6 = new GrassBlock();
  GB6->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB6->setPosition(Vector2f(45, 410));

  GrassBlock* GB7 = new GrassBlock();
  GB7->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB7->setPosition(Vector2f(90, 410));

  GrassBlock* GB8 = new GrassBlock();
  GB8->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB8->setPosition(Vector2f(135, 410));

  GrassBlock* GB10 = new GrassBlock();
  GB10->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB10->setPosition(Vector2f(180, 410));

  GrassBlock* GB11 = new GrassBlock();
  GB11->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB11->setPosition(Vector2f(225, 410));

  GrassBlock* GB12 = new GrassBlock();
  GB12->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB12->setPosition(Vector2f(270, 410));

  GrassBlock* GB13 = new GrassBlock();
  GB13->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB13->setPosition(Vector2f(315, 410));

  GrassBlock* GB14 = new GrassBlock();
  GB14->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB14->setPosition(Vector2f(360, 410));

  GrassBlock* GB15 = new GrassBlock();
  GB15->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB15->setPosition(Vector2f(405, 410));

  GrassBlock* GB16 = new GrassBlock();
  GB16->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB16->setPosition(Vector2f(450, 410));

  GrassBlock* GB17 = new GrassBlock();
  GB17->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB17->setPosition(Vector2f(495, 410));

  GrassBlock* GB18 = new GrassBlock();
  GB18->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB18->setPosition(Vector2f(540, 410));

  GrassBlock* GB19 = new GrassBlock();
  GB19->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB19->setPosition(Vector2f(585, 410));

  GrassBlock* GB20 = new GrassBlock();
  GB20->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB20->setPosition(Vector2f(630, 410));

  GrassBlock* GB21 = new GrassBlock();
  GB21->setImageRectAndTexture("data/imagens/Tiles2.png");
  GB21->setPosition(Vector2f(675, 410));

  LEntitys.pushEntity(static_cast<Entity*>(K));
  LEntitys.pushEntity(static_cast<Entity*>(GB1));
  LEntitys.pushEntity(static_cast<Entity*>(GB2));
  LEntitys.pushEntity(static_cast<Entity*>(GB3));
  LEntitys.pushEntity(static_cast<Entity*>(GB4));
  LEntitys.pushEntity(static_cast<Entity*>(GB5));
  LEntitys.pushEntity(static_cast<Entity*>(GB6));
  LEntitys.pushEntity(static_cast<Entity*>(GB7));
  LEntitys.pushEntity(static_cast<Entity*>(GB8));
  LEntitys.pushEntity(static_cast<Entity*>(GB9));
  LEntitys.pushEntity(static_cast<Entity*>(GB10));
  LEntitys.pushEntity(static_cast<Entity*>(GB11));
  LEntitys.pushEntity(static_cast<Entity*>(GB12));
  LEntitys.pushEntity(static_cast<Entity*>(GB13));
  LEntitys.pushEntity(static_cast<Entity*>(GB14));
  LEntitys.pushEntity(static_cast<Entity*>(GB15));
  LEntitys.pushEntity(static_cast<Entity*>(GB16));
  LEntitys.pushEntity(static_cast<Entity*>(GB17));
  LEntitys.pushEntity(static_cast<Entity*>(GB18));
  LEntitys.pushEntity(static_cast<Entity*>(GB19));
  LEntitys.pushEntity(static_cast<Entity*>(GB20));
  LEntitys.pushEntity(static_cast<Entity*>(GB21));

  run();
}

Phase::~Phase(){

}
