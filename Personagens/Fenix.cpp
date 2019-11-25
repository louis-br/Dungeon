#include "Fenix.h"

Fenix::Fenix(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Inimigo(pos, sf::Vector2f(159, 214), lista, vetor)
{
	vidas = 3;
	setTextura(GerenciadorGrafico::Texturas::Fenix);
}

Fenix::~Fenix() {

}

void Fenix::colidiuCom(Tipo tipo) {
	estado = Estado::Andando;
	if ((int)tipo > 0) {
		sentido = !sentido;
	}
}

void Fenix::printar(GerenciadorGrafico* grafico) {
	printarCoracoes(grafico);
	printarDano(grafico, 1.f);
	sentido = (int)(relogio.getElapsedTime().asSeconds() * 0.25f) % 2 == 0;
	if (!sentido) {
		sentido = -1;
	}
	mover(sf::Vector2f(sentido, -1));
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect((sentido < 0) * 159, 0, sentido * 159, 214));
	grafico->desenhar(sprite);
}

Fenix::BolaDeFogo::BolaDeFogo(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, sf::Vector2f(0, 0), lista, vetor)
{

}

Fenix::BolaDeFogo::~BolaDeFogo() {

}

Fenix::BolaDeFogo::Tipo Fenix::BolaDeFogo::getTipo() {
	return Tipo::Hostil;
}

void Fenix::BolaDeFogo::colidiuCom(Tipo tipo) {

}

void Fenix::BolaDeFogo::printar(GerenciadorGrafico* grafico) {

}