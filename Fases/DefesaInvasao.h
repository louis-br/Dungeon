#pragma once
#include "Fase.h"
#include "../Listas/ListaEntidade.h"
#include "../Blocos/Tijolo.h"

class DefesaInvasao : public Fase
{
public:
	DefesaInvasao(sf::RenderWindow* janela);
	~DefesaInvasao();
	void CriarTerreno();
};

