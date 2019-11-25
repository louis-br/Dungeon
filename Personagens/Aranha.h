#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Aranha : public Inimigo
	{
	public:
		Aranha(sf::Vector2f pos = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Aranha();
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
		void andar();
	};
}