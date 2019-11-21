#pragma once
#include "../Gerenciadores/GerenciadorGrafico.h"
#include "../Listas/ListaEntidade.h"

//class ListaEntidade;

class Entidade
{
protected:
	sf::Vector2f posicao;
	sf::Vector2f tamanho;
	float atrito;
public:
	enum class Tipo {
		Neutro,
		Hostil
	};

	Entidade(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	virtual ~Entidade();
	virtual void printar(GerenciadorGrafico* grafico) = 0;
	virtual Tipo getTipo();
	virtual void colidiuCom(Tipo tipo);
	sf::Vector2f getPosicao();
	sf::Vector2f getTamanho();
	void setPosicao(sf::Vector2f pos);
	void setTamanho(sf::Vector2f tam);
	void setAtrito(float at);
	float getAtrito();
};
