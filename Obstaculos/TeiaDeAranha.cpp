#include "TeiaDeAranha.h"

TeiaDeAranha::TeiaDeAranha(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista),
	textura(GerenciadorGrafico::getInstancia()->getTextura(
			GerenciadorGrafico::Texturas::TeiaDeAranha))
{
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
}

TeiaDeAranha::~TeiaDeAranha() {

}