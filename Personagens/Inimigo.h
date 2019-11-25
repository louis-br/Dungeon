#pragma once
#include "Personagem.h"

namespace Personagens {
	class Inimigo : public Personagem
	{
	public:
		Inimigo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Inimigo();
		Tipo getTipo();
		void colidiuCom(Tipo tipo);
	};
}