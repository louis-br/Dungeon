#pragma once
#include "Fase.h"
#include "../Listas/ListaEntidade.h"
#include "../Blocos/Tijolo.h"

class DefesaInvasao : public Fase
{
private:
	sf::Texture textura;
public:
	DefesaInvasao(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
	~DefesaInvasao();
	void criarTerreno();
};

