#pragma once
#include <SFML/Graphics.hpp>
#include "../Personagens/Jogador.h"
#include "../Principal/Menus/Menu.h"

class GerenciadorEntrada
{ 
private:
	Jogador* jogadores[2];
	Menu* menu;
	sf::RenderWindow* janela;
	static GerenciadorEntrada* instancia;
	GerenciadorEntrada(sf::RenderWindow* window = nullptr);
	~GerenciadorEntrada();
public:
	static GerenciadorEntrada* getInstancia();
	void setJogador(Jogador* jogador);
	void setMenu(Menu* m);
	void setJanela(sf::RenderWindow* window);
	void executar();
};
