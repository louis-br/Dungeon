#pragma once
#include <SFML/Graphics.hpp>
#include "../Listas/ListaEntidade.h"

class Fase
{
protected:
	ListaEntidade listaEntidade;
	sf::View camera;
public:
	Fase(sf::RenderWindow* janela = nullptr);
	virtual ~Fase();
	virtual void CriarTerreno() = 0;
	void Executar();
};