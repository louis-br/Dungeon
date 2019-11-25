#pragma once
#include "Fase.h"

class Floresta : public Fase
{
public:
	Floresta(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
	~Floresta();
	void criarTerreno();
};

