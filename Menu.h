#pragma once
#include "Entidade.h"

class Menu : public Entidade
{
private:
	sf::RectangleShape fundo;
	sf::Font fonte;
	sf::Text titulo;
public:
	Menu(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* grafico = nullptr);
	~Menu();
	void Executar();
	void CriarGraficos(ListaEntidade* grafico);
	void Apresentar(ListaEntidade& grafico);
};