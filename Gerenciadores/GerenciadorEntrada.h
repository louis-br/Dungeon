#pragma once
#include <SFML/Graphics.hpp>
#include "../Personagens/Jogador.h"
#include "../Principal/Menus/Menu.h"

namespace Gerenciadores {
	class GerenciadorEntrada
	{
	private:
		Personagens::Jogador* jogadores[2];
		Principal::Menus::Menu* menus[2];
		sf::RenderWindow* janela;
		static GerenciadorEntrada* instancia;
		GerenciadorEntrada();
		~GerenciadorEntrada();
	public:
		static GerenciadorEntrada* getInstancia();
		void setJogador(Personagens::Jogador* jogador);
		void setMenu(Principal::Menus::Menu* m);
		void setJanela(sf::RenderWindow* window);
		void executar();
	};
}