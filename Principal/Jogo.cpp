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
	//fase1(&janela, &jogador),
	fase(new Floresta(&janela, &jogador)),
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
	if (fase != nullptr) {
		delete fase;
	}
}

void Jogo::executar() {
	while (janela.isOpen())
	{
		grafico->limpar();
		entrada->executar();
		bool inicial = menuInicial.getLigado();
		bool pausa = menuPausa.getLigado();

        menuInicial.executar();

        if(menuInicial.getFase()){
            fase = &fase1;
        }
        else{
            fase = &fase2;
        }
        if (menuInicial.getSair()) {
            return;
        }
        fase->executar(inicial || pausa);

		if (inicial) {
			menuPausa.setLigado(false);
			menuInicial.printar(grafico);
            if (menuInicial.executar()) {
				if (menuInicial.getMultijogador()) {
					sf::Keyboard::Key teclas[4] = { sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S };
					jogador2.setTeclas(teclas);
					entrada->setJogador(&jogador2);
					fase->setJogador2(&jogador2);
				}
				if (fase != nullptr) {
					delete fase;
				}
				if (menuInicial.getFase()) {
					fase = static_cast<Fase*>(new Caverna(&janela, &jogador));
				}
				else {
					fase = static_cast<Fase*>(new Floresta(&janela, &jogador));
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
