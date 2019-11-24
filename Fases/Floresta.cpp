#include "Floresta.h"

Floresta::Floresta(sf::RenderWindow* janela, Cavaleiro* jog1) :
	Fase(janela, jog1)
{
	setTextura(GerenciadorGrafico::Texturas::Floresta);
	textura.setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 1920*2, 1080));
	criarTerreno();
}

Floresta::~Floresta() {

}

void Floresta::criarTerreno() {
	new Plataforma(sf::Vector2f(0, 268), sf::Vector2f(11500, 140), &listaEntidade, GerenciadorGrafico::Plataforma);
	new TeiaDeAranha(sf::Vector2f(0, 268), sf::Vector2f(100, 50), &listaEntidade);
	new Estalactite(sf::Vector2f(300, 0), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Fogo(sf::Vector2f(400, 268), sf::Vector2f(8, 15), &listaEntidade);
	new Anao(sf::Vector2f(500, 0), &listaEntidade, &vetorEntidadeFisica);
	new Aranha(sf::Vector2f(500, 0), &listaEntidade, &vetorEntidadeFisica);
	new Fenix(sf::Vector2f(600, 0), &listaEntidade, &vetorEntidadeFisica);
}