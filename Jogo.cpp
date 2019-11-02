#include "Jogo.h"

#define LARGURA 800
#define ALTURA 640
#define TITULO "Jogo"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	entrada(&janela),
	grafico(&janela),
	menu(sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA), &grafico)
{
	Executar();
}

Jogo::~Jogo() {

}

void Jogo::Executar() {
	
	while (janela.isOpen())
	{
		entrada.Executar();
		grafico.Executar();
	}
}
