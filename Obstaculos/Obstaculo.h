#pragma once
#include "../Entidades/Entidade.h"

namespace Obstaculos {
	class Obstaculo : public Entidades::Entidade
	{
	public:
		Obstaculo(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr);
		~Obstaculo();
		virtual void printar(Gerenciadores::GerenciadorGrafico* grafico);
	};
}
