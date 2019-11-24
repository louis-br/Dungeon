#include "Anao.h"

Anao::Anao(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Inimigo(pos, sf::Vector2f(36, 65), lista, vetor)
{
	setTextura(GerenciadorGrafico::Texturas::Anao);
	sprite.setTextureRect(sf::IntRect(30, 7, 36, 65));
	potencialVelocidade = sf::Vector2f(0.f, 130.f);
	potencialAceleracao = sf::Vector2f(100.f, 0.f);
	velocidadeMaxima = sf::Vector2f(130.f, 0.f);
}

Anao::~Anao() {

}

void Anao::printar(GerenciadorGrafico* grafico) {
	printarCoracoes(grafico);
	printarDano(grafico, 1.f);
	sentido = (int)(relogio.getElapsedTime().asSeconds() * 0.25f) % 2 == 0;
	if (!sentido) {
		sentido = -1;
	}
	mover(sf::Vector2f(sentido, 0));
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect(30 + (sentido < 0)*36, 7, sentido*36, 65));
	andar();
	grafico->desenhar(sprite);
}

void Anao::andar() {

}

//void Anao::colidiuCom(Tipo tipo) {

//}