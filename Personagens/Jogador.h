#pragma once
#include "Personagem.h"

class Jogador : public Personagem
{
private:
	sf::Keyboard::Key direita;
	sf::Keyboard::Key esquerda;
	sf::Keyboard::Key cima;
	sf::Keyboard::Key baixo;
	sf::Keyboard::Key teclas[4];
public:
	Jogador(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Jogador();
	void setTeclas(sf::Keyboard::Key* novo);
	sf::Keyboard::Key* getTeclas();
	void atualizarTeclas();
	void colidiuCom(Tipo tipo);
};

