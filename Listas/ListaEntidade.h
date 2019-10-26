#pragma once
#include "Lista.h"
#include "../Entidade.h"

class ListaEntidade
{
private:
	Lista<Entidade> LEs;
public:
	ListaEntidade();
	~ListaEntidade();
	Lista<Entidade>* getListaEntidades();
	void Inserir(Entidade* entidade = nullptr);
	void Excluir(Entidade* entidade = nullptr);
};

