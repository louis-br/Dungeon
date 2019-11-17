#pragma once
#include "../Gerenciadores/GerenciadorEntrada.h"
#include "../Gerenciadores/GerenciadorGrafico.h"
//#include "Menus/Menu.h"
#include "../Fases/DefesaInvasao.h"

class Jogo
{
private:
	sf::RenderWindow janela;
	GerenciadorEntrada* entrada;
	GerenciadorGrafico* grafico;
	DefesaInvasao fase1;

//	Menu menu;
public:
	Jogo();
	~Jogo();
	void executar();
};
