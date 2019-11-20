#pragma once
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Tijolo : public Entidade
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	Tijolo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Tijolo();
	Entidade::Tipo getTipo();
	void printar(GerenciadorGrafico* grafico);
};

