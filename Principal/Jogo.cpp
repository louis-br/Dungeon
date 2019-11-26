#include "Jogo.h"

#define LARGURA 1280
#define ALTURA 720
#define TITULO "Dungeon++"

Principal::Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	menuInicial(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	menuPausa(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	entrada(Gerenciadores::GerenciadorEntrada::getInstancia()),
	grafico(Gerenciadores::GerenciadorGrafico::getInstancia()),
	jogador(),
	//fase1(&janela, &jogador),
	fase(new Fases::Floresta(&janela, &jogador)),
    pausado(false),
    geraChefao(true)
{
	janela.setFramerateLimit(60);
	entrada->setMenu(static_cast<Menus::Menu*>(&menuInicial));
	entrada->setMenu(static_cast<Menus::Menu*>(&menuPausa));
	entrada->setJanela(&janela);
	entrada->setJogador(static_cast<Personagens::Jogador*>(&jogador));
	grafico->setJanela(&janela);
	executar();
}

Principal::Jogo::~Jogo() {
	if (fase != nullptr) {
		delete fase;
	}
}

void Principal::Jogo::executar() {
	while (janela.isOpen())
	{
		grafico->limpar();
		entrada->executar();
		bool inicial = menuInicial.getLigado();
        bool pausa = menuPausa.getLigado();

        menuInicial.executar();

        if(jogador.getPosicao().x > 9300 && controlFase == 1){
            delete fase;
            fase = static_cast<Fases::Fase*>(new Fases::Caverna(&janela, &jogador));
            controlFase = 2;
        }

        if(jogador.getPosicao().x > 9500  && controlFase == 2 && geraChefao){
            geraChefao = false;
            new Personagens::Fenix(sf::Vector2f(10500, -100), &fase->listaEntidade, &fase->vetorEntidadeFisica);
        }

        fase->executar(inicial || pausa);
		if (inicial) {
			menuPausa.setLigado(false);
			menuInicial.printar(grafico);
			jogador.setPosicao(sf::Vector2f(0, 0));
			jogador2.setPosicao(sf::Vector2f(0, 0));
            if (menuInicial.executar()) {
				if (menuInicial.getSair()) {
					return;
				}
				if (fase != nullptr) {
					delete fase;
				}
				if (menuInicial.getFase()) {
                    controlFase = 2;
					fase = static_cast<Fases::Fase*>(new Fases::Caverna(&janela, &jogador));
				}
				else {
                    controlFase = 1;
                    fase = static_cast<Fases::Fase*>(new Fases::Floresta(&janela, &jogador));
				}
				if (menuInicial.getMultijogador()) {
					sf::Keyboard::Key teclas[4] = { sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S };
					jogador2.setTeclas(teclas);
					entrada->setJogador(&jogador2);
					fase->setJogador2(&jogador2);
				}
				else {
					entrada->setJogador(nullptr);
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
