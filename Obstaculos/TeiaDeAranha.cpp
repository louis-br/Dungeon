#include "TeiaDeAranha.h"

TeiaDeAranha::TeiaDeAranha(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista)
{
	atrito = 5.f;
	setTextura(GerenciadorGrafico::Texturas::TeiaDeAranha);
	textura.setRepeated(true);
	sprite.setPosition(pos - sf::Vector2f(0, tamanho.y));
	tamanho = sf::Vector2f(tamanho.x, 1);
}

TeiaDeAranha::~TeiaDeAranha() {

}

void TeiaDeAranha::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}