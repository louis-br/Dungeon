#include "Jogo.h"

#define LARGURA 200
#define ALTURA 200
#define TITULO "Jogo"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA), TITULO),
	entrada(&janela)
{
	Executar();
}

Jogo::~Jogo() {

}

void Jogo::Executar() {
	
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (janela.isOpen())
	{
		entrada.Executar();

		janela.clear();
		janela.draw(shape);
		janela.display();
	}
}