#pragma once
#include <SFML/Graphics.hpp>
#include "../Listas/ListaEntidade.h"
#include "../Personagens/Guerreiro.h"

class Fase
{
protected:
	ListaEntidade listaEntidade;
	sf::View camera;
	Guerreiro jogador;
public:
	Fase(sf::RenderWindow* janela = nullptr);
	virtual ~Fase();
	virtual void criarTerreno() = 0;
	void executar();
};