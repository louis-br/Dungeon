#include "Fase.h"

Fase::Fase(sf::RenderWindow* window) :
	fisico(GerenciadorFisico::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	janela(window),
	camera(),
	listaEntidade(),
	vetorEntidadeFisica(),
	fundo(sf::Vector2f(0, 0), sf::Vector2f(100000, 5000), &listaEntidade),
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
