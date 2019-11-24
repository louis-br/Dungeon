#pragma once
#include "Fase.h"
#include "../Listas/ListaEntidade.h"
#include "../Plataformas/Plataforma.h"
#include "../Obstaculos/TeiaDeAranha.h"
#include "../Obstaculos/Estalactite.h"
#include "../Obstaculos/Fogo.h"
#include "../Personagens/Anao.h"
#include "../Personagens/Aranha.h"

class Floresta : public Fase
{
public:
	Floresta(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
	~Floresta();
	void criarTerreno();
};

