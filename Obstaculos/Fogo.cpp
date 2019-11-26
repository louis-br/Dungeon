#include "Fogo.h"

Obstaculos::Fogo::Fogo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista) :
	Obstaculo(pos, tam, lista)
{
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Fogo);
	textura.setRepeated(true);
	sprite.setPosition(pos - sf::Vector2f(0, tamanho.y));
	tamanho = sf::Vector2f(tamanho.x, 1);
}

Obstaculos::Fogo::~Fogo() {

}

Obstaculos::Fogo::Tipo Obstaculos::Fogo::getTipo() {
	return Tipo::Hostil;
}