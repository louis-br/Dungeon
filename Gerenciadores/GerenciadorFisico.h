#pragma once
#include <SFML/System.hpp>
#include "../Entidades/Entidade.h"
#include "../Entidades/EntidadeFisica.h"

class GerenciadorFisico
{
private:
	static GerenciadorFisico* instancia;
	list<EntidadeFisica*> moveis; //mudar para as classes listas
	list<Entidade> entidades;
	sf::Clock relogio;
	GerenciadorFisico();
	~GerenciadorFisico();
public:
	static GerenciadorFisico* getInstancia();
	sf::Vector2f colidir(Entidade* A, Entidade* B);
	void executar();
};