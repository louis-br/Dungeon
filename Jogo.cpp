#include "Jogo.h"

#define LARGURA 200
#define ALTURA 200
#define TITULO "Jogo"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA), TITULO),
	entrada(&janela),
	grafico(&janela),
	menu(&grafico)
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