#pragma once
#include "Gerenciadores/GerenciadorEntrada.h"
#include "Gerenciadores/GerenciadorGrafico.h"
#include "Menu.h"

class Jogo
{
private:
	sf::RenderWindow janela;
	GerenciadorEntrada entrada;
	GerenciadorGrafico grafico;
	Menu menu;
public:
	Jogo();
	~Jogo();
	void Executar();
};