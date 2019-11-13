#include "GerenciadorEntrada.h"

GerenciadorEntrada::GerenciadorEntrada(sf::RenderWindow* window) :
janela(window)
{

}

GerenciadorEntrada::~GerenciadorEntrada() {

}

void GerenciadorEntrada::Executar() {
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