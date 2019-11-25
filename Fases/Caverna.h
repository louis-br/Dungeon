#pragma once
#include "Fase.h"
#include "../Personagens/Fenix.h"

namespace Fases {
	class Caverna : public Fase
	{
	public:
		Caverna(sf::RenderWindow* janela = nullptr, Personagens::Cavaleiro* jog1 = nullptr);
		~Caverna();
		void criarTerreno();
	};
}
