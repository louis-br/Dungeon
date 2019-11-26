#pragma once
#include "../Gerenciadores/GerenciadorEntrada.h"
#include "../Gerenciadores/GerenciadorGrafico.h"
#include "Menus/Inicial.h"
#include "Menus/Pausa.h"
#include "../Fases/Floresta.h"
#include "../Fases/Caverna.h"

namespace Principal {
	class Jogo
	{
	private:
        bool geraChefao;
        int controlFase;
		sf::RenderWindow janela;
		Menus::Inicial menuInicial;
		Menus::Pausa menuPausa;
		Gerenciadores::GerenciadorEntrada* entrada;
		Gerenciadores::GerenciadorGrafico* grafico;
		Personagens::Cavaleiro jogador;
		Personagens::Cavaleiro jogador2;
		//Caverna fase1;
		Fases::Fase* fase;
		//Pausa menuPausa;
		bool pausado;
	public:
		Jogo();
		~Jogo();
		void executar();
	};
}
