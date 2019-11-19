#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Personagem(pos, tam, lista, vetor),
	direita(sf::Keyboard::Right),
	esquerda(sf::Keyboard::Left),
	cima(sf::Keyboard::Up),
	baixo(sf::Keyboard::Down),
	teclas{direita, esquerda, cima, baixo}
{

}

Jogador::~Jogador() {

}

void Jogador::setTeclas(sf::Keyboard::Key* novo) {
	for (int i = 0; i < 4; ++i) {
		teclas[i] = novo[i];
	}
	direita = teclas[0];
	esquerda = teclas[1];
	cima = teclas[2];
	baixo = teclas[3];
}

sf::Keyboard::Key* Jogador::getTeclas() {
	return teclas;
}

void Jogador::atualizarTeclas() {
	mover(sf::Vector2f(
		sf::Keyboard::isKeyPressed(direita) - sf::Keyboard::isKeyPressed(esquerda),
		sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima)
	));
}
