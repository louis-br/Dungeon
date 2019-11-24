#include "Jogo.h"

#define LARGURA 1280
#define ALTURA 720
#define TITULO "Dungeon++"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	entrada(GerenciadorEntrada::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	jogador(),
	fase1(&janela, &jogador),
	fase(&fase1),
	menuInicial(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	pausado(false)
{
	janela.setFramerateLimit(60);
	entrada->setJanela(&janela);
	grafico->setJanela(&janela);
	entrada->setJogador(static_cast<Jogador*>(&jogador));
	entrada->setMenu(static_cast<Menu*>(&menuInicial));
	executar();
}

Jogo::~Jogo() {

}

void Jogo::executar() {
	while (janela.isOpen())
	{
		grafico->limpar();
		entrada->executar();
		bool ligado = menuInicial.getLigado();
		fase->executar(ligado);
		if (ligado) {
			menuInicial.printar(grafico);
			if (menuInicial.executar()) {
				entrada->setMenu(nullptr);
				if (menuInicial.getSair()) {
					return;
				}
				if (menuInicial.getMultijogador()) {
					sf::Keyboard::Key teclas[4] = { sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S };
					jogador2.setTeclas(teclas);
					entrada->setJogador(&jogador2);
					fase->setJogador2(&jogador2);
				}
			}
		}
		grafico->atualizarTela();
	}
}
