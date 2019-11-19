#include "Fase.h"

Fase::Fase(sf::RenderWindow* window) :
	fisico(GerenciadorFisico::getInstancia()),
	janela(window),
	camera(),
	listaEntidade(),
	vetorEntidadeFisica(),
	jogador(sf::Vector2f(0, 0), &listaEntidade, &vetorEntidadeFisica)
{
	//camera.setCenter(200.f, 150.f); //trocar para personagem
	if (janela != nullptr) {
		camera.setSize(static_cast<sf::Vector2f>(janela->getSize()));
		camera.zoom(0.5f);
		janela->setView(camera);
	}
	GerenciadorEntrada::getInstancia()->setJogador(static_cast<Jogador*>(&jogador));
}

Fase::~Fase() {

}

void Fase::executar() {
	//std::cout << jogador.getVelocidade().x << ':' << jogador.getVelocidade().y << '\n';
	camera.setCenter(jogador.getPosicao() + jogador.getTamanho() * 0.5f);
	janela->setView(camera);
	listaEntidade.printar();
	fisico->executar(vetorEntidadeFisica, listaEntidade);
}
