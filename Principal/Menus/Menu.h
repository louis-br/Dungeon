#pragma once
#include "../../Entidades/Entidade.h"

class Menu : public Entidade
{
protected:
	sf::RenderWindow* janela;
	sf::RectangleShape fundo;
	sf::Font fonte;
	sf::Text titulo;
	sf::Keyboard::Key cima;
	sf::Keyboard::Key baixo;
	sf::Keyboard::Key confirma;
	int opcao;
	bool confirmado;
public:
	Menu(sf::RenderWindow* window = nullptr, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
	~Menu();
	void atualizarTeclas();
};