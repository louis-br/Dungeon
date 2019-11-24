#include "Fogo.h"

Fogo::Fogo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista)
{
	setTextura(GerenciadorGrafico::Texturas::Fogo);
	textura.setRepeated(true);
	sprite.setPosition(pos - sf::Vector2f(0, tamanho.y));
	tamanho = sf::Vector2f(tamanho.x, 1);
}

Fogo::~Fogo() {

}

Fogo::Tipo Fogo::getTipo() {
	return Tipo::Hostil;
}

void Fogo::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}