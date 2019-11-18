#include "Fase.h"

Fase::Fase(sf::RenderWindow* janela) :
	fisico(GerenciadorFisico::getInstancia()),
	listaEntidade(),
	vetorEntidadeFisica(),
	camera(),
	jogador(sf::Vector2f(0, 0), &listaEntidade, &vetorEntidadeFisica)
{
	camera.setCenter(200.f, 150.f); //trocar para personagem
	camera.setSize(static_cast<sf::Vector2f>(janela->getSize()));
	camera.zoom(0.5f);
	if (janela != nullptr) {
		janela->setView(camera);
	}
}

Fase::~Fase() {

}

void Fase::executar() {
	listaEntidade.printar();
	fisico->executar(vetorEntidadeFisica, listaEntidade);
}