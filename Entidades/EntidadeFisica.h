#pragma once
#include "Entidade.h"

class EntidadeFisica : public Entidade
{
protected:
	sf::Vector2f velocidade;
	sf::Vector2f aceleracao;
	sf::Vector2f velocidadeMaxima;
public:
	EntidadeFisica(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~EntidadeFisica();
};

