#include "Jogo.h"

#define LARGURA 1280
#define ALTURA 720
#define TITULO "Dungeon++"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	menuInicial(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	menuPausa(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	entrada(GerenciadorEntrada::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	jogador(),
	fase1(&janela, &jogador),
	fase(&fase1),
	pausado(false)
{
	janela.setFramerateLimit(60);
	entrada->setMenu(static_cast<Menu*>(&menuInicial));
	entrada->setMenu(static_cast<Menu*>(&menuPausa));
	entrada->setJanela(&janela);
	entrada->setJogador(static_cast<Jogador*>(&jogador));
	grafico->setJanela(&janela);
	executar();
}

Jogo::~Jogo() {

}

void Jogo::executar() {
	while (janela.isOpen())
	{
		grafico->limpar();
		entrada->executar();
		bool inicial = menuInicial.getLigado();
		bool pausa = menuPausa.getLigado();
		fase->executar(inicial || pausa);
		if (inicial) {
			menuPausa.setLigado(false);
			menuInicial.printar(grafico);
			if (menuInicial.executar()) {
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
		if (pausa) {
			menuPausa.printar(grafico);
			if (menuPausa.executar()) {
				if (menuPausa.getSair()) {
					menuInicial.setLigado(true);
				}
			}
		}
		grafico->atualizarTela();
	}
}
