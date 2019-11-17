#pragma once
#include <list>
using namespace std;

#include "../Gerenciadores/GerenciadorFisico.h"

class EntidadeFisica;

class ListaEntidadeFisica
{
private:
	//Lista<Entidade> LEs;
	list<EntidadeFisica*> elementos;
	list<EntidadeFisica*>::iterator iterador;
public:
	ListaEntidadeFisica();
	~ListaEntidadeFisica();
	void inserir(EntidadeFisica* entidade);
	list<EntidadeFisica*>* getLista();
	//void printar();
};
