#pragma once
#include "Lista.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

namespace Entidades {
	class Entidade;
}

namespace Listas {
	class ListaEntidade
	{
	private:
		Gerenciadores::GerenciadorGrafico* grafico;
		Lista<Entidades::Entidade> LEs;
	public:
		ListaEntidade();
		~ListaEntidade();
		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* getPrimeiro();
		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* getUltimo();
		void empilharTras(Entidades::Entidade* entidade);
		void remover(Entidades::Entidade* entidade);
		void printar();
	};
}