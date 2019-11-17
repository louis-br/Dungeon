#pragma once
#include "../Listas/ListaEntidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Entidade
{
protected:
	sf::Vector2f posicao;
	sf::Vector2f tamanho;
public:
	Entidade(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Entidade();
	virtual void printar(GerenciadorGrafico* grafico) = 0;
	sf::Vector2f getPosicao();
	sf::Vector2f getTamanho();
	void setPosicao(sf::Vector2f pos);
	void setTamanho(sf::Vector2f tam);
};
