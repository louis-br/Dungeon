#pragma once
#include "Menu.h"

namespace Principal {
	namespace Menus {
		class Pausa : public Menu
		{
		private:
			sf::Text opcoes[2];
			bool fase;
			bool multijogador;
			bool sair;
		public:
			enum Opcoes {
				Continuar,
				Sair
			};

			Pausa(sf::RenderWindow* window = nullptr, sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0));
			~Pausa();
			bool getSair();
			int executar();
			void printar(Gerenciadores::GerenciadorGrafico* grafico);
			void atualizarTeclas();
		};
	}
}