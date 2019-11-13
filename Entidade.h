#pragma once
#include "Gerenciadores/GerenciadorGrafico.h"

class Entidade
{
protected:
	sf::Vector2f posicao;
	sf::Vector2f tamanho;
public:
	Entidade(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), GerenciadorGrafico* grafico = nullptr);
	~Entidade();
	virtual void Apresentar(GerenciadorGrafico& grafico) = 0;
};

