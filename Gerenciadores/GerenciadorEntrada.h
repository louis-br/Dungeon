#pragma once
#include <SFML/Graphics.hpp>
#include "../Personagens/Jogador.h"

class GerenciadorEntrada
{ 
private:
	Jogador* jogadores[2];
	sf::RenderWindow* janela;
	static GerenciadorEntrada* instancia;
	GerenciadorEntrada(sf::RenderWindow* window = nullptr);
	~GerenciadorEntrada();
public:
	static GerenciadorEntrada* getInstancia();
	void setJogador(Jogador* jogador);
	void setJanela(sf::RenderWindow* window);
	void executar();
};
