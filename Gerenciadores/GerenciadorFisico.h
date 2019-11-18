#pragma once
#include <list>
#include <cstdlib>
#include <SFML/System.hpp>
#include "../Entidades/Entidade.h"
#include "../Entidades/EntidadeFisica.h"
#include "../Listas/ListaEntidade.h"
#include "../Listas/VetorEntidadeFisica.h"

class GerenciadorFisico
{
private:
	static GerenciadorFisico* instancia;
	sf::Clock relogio;
	GerenciadorFisico();
	~GerenciadorFisico();
public:
	static GerenciadorFisico* getInstancia();
	sf::Vector2f colidir(Entidade* A, Entidade* B);
	void executar(VetorEntidadeFisica& moveis, ListaEntidade& entidades);
};