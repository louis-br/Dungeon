#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Personagem(pos, tam, lista),
	direita(sf::Keyboard::Key::Right),
	esquerda(sf::Keyboard::Key::Left),
	cima(sf::Keyboard::Key::Up),
	baixo(sf::Keyboard::Key::Down)
{

}

Jogador::~Jogador() {

}

void Jogador::AtualizarTeclas() {
	Mover(sf::Vector2f(
		sf::Keyboard::isKeyPressed(direita) - sf::Keyboard::isKeyPressed(esquerda),
		sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima)
	));
}