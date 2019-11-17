#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Personagem(pos, tam, lista),
	direita(sf::Keyboard::Right),
	esquerda(sf::Keyboard::Left),
	cima(sf::Keyboard::Up),
	baixo(sf::Keyboard::Down)
{

}

Jogador::~Jogador() {

}

void Jogador::atualizarTeclas() {
	mover(sf::Vector2f(
		sf::Keyboard::isKeyPressed(direita) - sf::Keyboard::isKeyPressed(esquerda),
		sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima)
	));
}