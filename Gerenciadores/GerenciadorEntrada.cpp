#include "GerenciadorEntrada.h"

GerenciadorEntrada::GerenciadorEntrada(sf::RenderWindow* window) :
jogadores{nullptr, nullptr},
janela(window)
{

}

GerenciadorEntrada::~GerenciadorEntrada() {

}

GerenciadorEntrada* GerenciadorEntrada::getInstancia()
{
	if (instancia == nullptr) {
		instancia = new GerenciadorEntrada();
	}
	return instancia;
}

void GerenciadorEntrada::setJogador(Jogador* jogador) {
	if (jogadores[0] == nullptr) {
		jogadores[0] = jogador;
	}
	else {
		jogadores[1] = jogador;
	}
}

void GerenciadorEntrada::setJanela(sf::RenderWindow* window) {
	janela = window;
}

void GerenciadorEntrada::executar() {
	if (janela != nullptr) {
		sf::Event event;
		while (janela->pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				janela->close();
				break;
			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				for (int i = 0; i < 2; ++i) {
					if (jogadores[i] != nullptr) {
						sf::Keyboard::Key* teclas = jogadores[i]->getTeclas();
						for (int j = 0; j < 4; ++j) {
							if (event.key.code == teclas[j]) {
								jogadores[i]->atualizarTeclas();
								break;
							}
						}
					}
				}
				break;
			default:
				break;
			}
		}
	}
}

GerenciadorEntrada* GerenciadorEntrada::instancia(nullptr);