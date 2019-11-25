#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Fenix : public Inimigo
	{
	private:
		class BolaDeFogo : public EntidadeFisica {
		private:
			bool visivel;
		public:
			BolaDeFogo(sf::Vector2f pos = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
			~BolaDeFogo();
			Tipo getTipo();
			void colidiuCom(Tipo tipo);
			void printar(Gerenciadores::GerenciadorGrafico* grafico);
			void setVisivel(bool v);
		};
		BolaDeFogo* bolaDeFogo;
	public:
		Fenix(sf::Vector2f pos = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Fenix();
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
	};
}