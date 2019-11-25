#pragma once
#include "Fase.h"

namespace Fases {
	class Floresta : public Fase
	{
	public:
		Floresta(sf::RenderWindow* janela = nullptr, Personagens::Cavaleiro* jog1 = nullptr);
		~Floresta();
		void criarTerreno();
	};
}