#pragma once
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Plataforma : public Entidade
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	Plataforma(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, GerenciadorGrafico::Texturas tex = GerenciadorGrafico::Texturas::Plataforma);
	~Plataforma();
	Entidade::Tipo getTipo();
	void printar(GerenciadorGrafico* grafico);
};

