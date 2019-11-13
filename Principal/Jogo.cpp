#include "Jogo.h"

#define LARGURA 800
#define ALTURA 640
#define TITULO "Jogo"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	entrada(GerenciadorEntrada::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia())
//	menu(sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA))
{
	entrada->setJanela(&janela);
	grafico->setJanela(&janela);
	Executar();
}

Jogo::~Jogo() {

}

void Jogo::Executar() {
	
	while (janela.isOpen())
	{
		entrada->Executar();
		//grafico.Executar();
	}
}
