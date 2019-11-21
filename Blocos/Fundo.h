#pragma once
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Fundo : public Entidade
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	Fundo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Fundo();
	void printar(GerenciadorGrafico* grafico);
};

