#pragma once
#include "Lista.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

class Entidade;

class ListaEntidade
{
private:
	GerenciadorGrafico* grafico;
	Lista<Entidade> LEs;
public:
	ListaEntidade();
	~ListaEntidade();
	Lista<Entidade>::Elemento<Entidade>* getPrimeiro();
	Lista<Entidade>::Elemento<Entidade>* getUltimo();
	void empilharTras(Entidade* entidade);
	void printar();
};
