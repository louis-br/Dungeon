#pragma once
#include "Obstaculo.h"
#include "../Entidades/EntidadeFisica.h"

namespace Obstaculos {
	class Estalactite : public Obstaculo, public Entidades::EntidadeFisica
	{
	public:
		Estalactite(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Estalactite();
		Tipo getTipo();
		void colidiuCom(Tipo tipo);
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
	};
}