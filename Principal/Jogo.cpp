#include "Jogo.h"

#define LARGURA 800
#define ALTURA 600
#define TITULO "Jogo"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	entrada(GerenciadorEntrada::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	fase1(&janela)
//	menu(sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA))
{
	//janela.setFramerateLimit(5);
	entrada->setJanela(&janela);
	grafico->setJanela(&janela);
	executar();
}

Jogo::~Jogo() {

}

void Jogo::executar() {
	
	while (janela.isOpen())
	{
		entrada->executar();
		fase1.executar();
		//grafico.executar();
	}
}
