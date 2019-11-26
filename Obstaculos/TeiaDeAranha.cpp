#include "TeiaDeAranha.h"

Obstaculos::TeiaDeAranha::TeiaDeAranha(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista) :
	Obstaculo(pos, tam, lista)
{
	atrito = 5.f;
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::TeiaDeAranha);
	textura.setRepeated(true);
	sprite.setPosition(pos - sf::Vector2f(0, tamanho.y));
	tamanho = sf::Vector2f(tamanho.x, 1);
}

Obstaculos::TeiaDeAranha::~TeiaDeAranha() {

}