#include "GerenciadorEntrada.h"

Gerenciadores::GerenciadorEntrada::GerenciadorEntrada() :
jogadores{nullptr, nullptr},
menus{nullptr, nullptr},
janela(nullptr)
{

}

Gerenciadores::GerenciadorEntrada::~GerenciadorEntrada() {

}

Gerenciadores::GerenciadorEntrada* Gerenciadores::GerenciadorEntrada::getInstancia()
{
	if (instancia == nullptr) {
		instancia = new GerenciadorEntrada();
	}
	return instancia;
}

void Gerenciadores::GerenciadorEntrada::setJogador(Personagens::Jogador* jogador) {
	if (jogadores[0] == nullptr) {
		jogadores[0] = jogador;
	}
	else {
		jogadores[1] = jogador;
	}
}

void Gerenciadores::GerenciadorEntrada::setMenu(Principal::Menus::Menu* m) {
	if (menus[0] == nullptr) {
		menus[0] = m;
	}
	else {
		menus[1] = m;
	}
}

void Gerenciadores::GerenciadorEntrada::setJanela(sf::RenderWindow* window) {
	janela = window;
}

void Gerenciadores::GerenciadorEntrada::executar() {
	if (janela != nullptr) {
		sf::Event event;
		while (janela->pollEvent(event))
		{
			switch (event.type) {
			case sf::Event::Closed:
				janela->close();
				break;
			case sf::Event::Resized:
				janela->setSize(sf::Vector2u(event.size.width, event.size.height));
			case sf::Event::KeyPressed:
			case sf::Event::KeyReleased:
				if (menus[1] != nullptr) {
					menus[1]->atualizarTeclas();
				}
				if (menus[0] != nullptr && menus[0]->getLigado()) {
					menus[0]->atualizarTeclas();
				}
				else if (menus[1] != nullptr && !menus[1]->getLigado()) {
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
				}
				break;
			default:
				break;
			}
		}
	}
}

Gerenciadores::GerenciadorEntrada* Gerenciadores::GerenciadorEntrada::instancia(nullptr);