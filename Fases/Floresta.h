#pragma once
#include "Fase.h"
#include "../Listas/ListaEntidade.h"
#include "../Plataformas/Plataforma.h"

class Floresta : public Fase
{
private:
	sf::Texture textura;
public:
	Floresta(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
	~Floresta();
	void criarTerreno();
};

