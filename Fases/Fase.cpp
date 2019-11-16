#include "Fase.h"

Fase::Fase(sf::RenderWindow* janela) :
	listaEntidade(),
	camera(),
	jogador(sf::Vector2f(0, 0), &listaEntidade)
{
	camera.setCenter(100.f, 75.f); //trocar para personagem
	camera.setSize(static_cast<sf::Vector2f>(janela->getSize()));
	camera.zoom(0.25f);
	if (janela != nullptr) {
		janela->setView(camera);
	}
}

Fase::~Fase() {

}

void Fase::Executar() {
	listaEntidade.Printar();
}