#include "GerenciadorEntrada.h"

GerenciadorEntrada::GerenciadorEntrada(sf::RenderWindow* window) :
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
					break;

				case sf::Event::KeyReleased:
					break;

				default:
					break;
			}
		}
	}
}

GerenciadorEntrada* GerenciadorEntrada::instancia(nullptr);