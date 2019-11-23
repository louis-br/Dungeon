#include "Jogo.h"

#define LARGURA 800
#define ALTURA 600
#define TITULO "Dungeon++"

Jogo::Jogo() :
	janela(sf::VideoMode(LARGURA, ALTURA, 16), TITULO),
	entrada(GerenciadorEntrada::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	jogador(),
	fase1(&janela, &jogador),
	fase(&fase1),
	menuInicial(&janela, sf::Vector2f(0, 0), sf::Vector2f(LARGURA, ALTURA)),
	menuLigado(true),
	pausado(false),
	multijogador(false)
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
		fase->executar(menuLigado);
		if (menuLigado) {
			menuInicial.printar(grafico);
			int opcao = menuInicial.executar();
			if (opcao >= 0) {
				menuLigado = false;
				switch (opcao) {
				case Inicial::Opcoes::Fase1:
					std::cout << "Fase1\n";
					fase = &fase1;
					break;
				case Inicial::Opcoes::Fase2:
					std::cout << "Fase2\n";
					break;
				case Inicial::Opcoes::Jogadores:
					menuLigado = true;
					multijogador = !multijogador;
					menuInicial.setMultijogador(multijogador);
					break;
				case Inicial::Opcoes::Sair:
					return;
				}
				if (!menuLigado) {
					entrada->setMenu(nullptr);
					if (multijogador) {
						sf::Keyboard::Key teclas[4] = { sf::Keyboard::D, sf::Keyboard::A, sf::Keyboard::W, sf::Keyboard::S };
						jogador2.setTeclas(teclas);
						entrada->setJogador(&jogador2);
						fase->setJogador2(&jogador2);
					}
				}
			}
		}
		grafico->atualizarTela();
	}
}
