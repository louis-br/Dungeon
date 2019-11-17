#pragma once
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Tijolo : public Entidade
{
private:
	sf::IntRect retangulo;
	sf::Texture textura;
	sf::Sprite sprite;
public:
	Tijolo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~Tijolo();
	void printar(GerenciadorGrafico* grafico);
};

