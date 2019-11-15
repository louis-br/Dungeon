#pragma once
#include <SFML/System.hpp>
#include "../Entidades/Entidade.h"

class GerenciadorFisico
{
private:
	static GerenciadorFisico* instancia;
	GerenciadorFisico();
	~GerenciadorFisico();
public:
	static GerenciadorFisico* getInstancia();
	sf::Vector2f Colidir(Entidade* A, Entidade* B);
};