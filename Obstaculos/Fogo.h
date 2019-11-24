#pragma once
#include "../Entidades/Entidade.h"

class Fogo : public Entidade
{
public:
	Fogo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Fogo();
	Tipo getTipo();
	void printar(GerenciadorGrafico* grafico);
};

