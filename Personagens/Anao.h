#pragma once
#include "Inimigo.h"

namespace Personagens {
	class Anao : public Inimigo
	{
	public:
		Anao(sf::Vector2f pos = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Anao();
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
		void andar();
		//void colidiuCom(Tipo tipo);
	};
}