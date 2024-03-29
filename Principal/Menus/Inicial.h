#pragma once
#include "Menu.h"

namespace Principal {
	namespace Menus {
		class Inicial : public Menu
		{
		private:
			sf::Text opcoes[4];
			bool fase;
			bool multijogador;
			bool sair;
		public:
			enum Opcoes {
				Fase1,
				Fase2,
				Jogadores,
				Sair
			};

			Inicial(sf::RenderWindow* window = nullptr, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Inicial();
			bool getFase();
			bool getMultijogador();
			bool getSair();
			int executar();
			void printar(Gerenciadores::GerenciadorGrafico* grafico);

		};
	}
}