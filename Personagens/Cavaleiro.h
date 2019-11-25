#pragma once
#include "Jogador.h"

namespace Personagens {
	class Cavaleiro : public Jogador
	{
	public:
		Cavaleiro(sf::Vector2f pos = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Cavaleiro();
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
		void andar();
		void pular();
		void atacar();
	};
}