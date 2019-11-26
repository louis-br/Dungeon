#pragma once
#include "Obstaculo.h"

namespace Obstaculos {
	class TeiaDeAranha : public Obstaculo
	{
	public:
		TeiaDeAranha(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr);
		~TeiaDeAranha();
	};
}