#pragma once
#include <list>
#include <cstdlib>
#include <SFML/System.hpp>
#include "../Entidades/Entidade.h"
#include "../Entidades/EntidadeFisica.h"
#include "../Listas/ListaEntidade.h"
#include "../Listas/VetorEntidadeFisica.h"

namespace Gerenciadores {
	class GerenciadorFisico
	{
	private:
		sf::Vector2f gravidade;
		static GerenciadorFisico* instancia;
		sf::Clock relogio;
		GerenciadorFisico();
		~GerenciadorFisico();
	public:
		static GerenciadorFisico* getInstancia();
		void reiniciarRelogio();
		sf::Vector2f colidir(Entidades::Entidade* A, Entidades::Entidade* B);
		void executar(Listas::VetorEntidadeFisica& moveis, Listas::ListaEntidade& entidades);
	};
}