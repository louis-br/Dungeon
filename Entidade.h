#pragma once
#include <SFML/System.hpp>
#include "Gerenciadores/GerenciadorGrafico.h"

class Entidade
{
protected:
	sf::Vector2i posicao;
	sf::Vector2u tamanho;
public:
	Entidade(int x = 0, int y = 0, unsigned largura = 0, unsigned altura = 0);
	~Entidade();
	virtual void Apresentar(GerenciadorGrafico& grafico) = 0;
};

