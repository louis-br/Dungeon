#pragma once
#include "../Gerenciadores/GerenciadorEntrada.h"
#include "../Gerenciadores/GerenciadorGrafico.h"
#include "Menus/Inicial.h"
#include "Menus/Pausa.h"
#include "../Fases/Floresta.h"

class Jogo
{
private:
	sf::RenderWindow janela;
	Inicial menuInicial;
	Pausa menuPausa;
	GerenciadorEntrada* entrada;
	GerenciadorGrafico* grafico;
	Cavaleiro jogador;
	Cavaleiro jogador2;
	Floresta fase1;
	Fase* fase;
	//Pausa menuPausa;
	bool pausado;
public:
	Jogo();
	~Jogo();
	void executar();
};
