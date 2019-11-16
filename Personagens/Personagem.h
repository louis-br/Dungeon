#pragma once
#include "../Entidades/EntidadeFisica.h"

class Personagem : public EntidadeFisica
{
private:
	sf::Vector2f potencialVelocidade;
	sf::Vector2f potencialAceleracao;
public:
	Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Personagem();
	void Mover(sf::Vector2f direcao = sf::Vector2f(0, 0));
};