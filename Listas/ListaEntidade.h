#pragma once
#include <list>
using namespace std;

#include "../Gerenciadores/GerenciadorGrafico.h"

class Entidade;

class ListaEntidade
{
private:
	GerenciadorGrafico* grafico;
	//Lista<Entidade> LEs;
	list<Entidade*> elementos;
	list<Entidade*>::iterator iterador;
public:
	ListaEntidade();
	~ListaEntidade();
	void Inserir(Entidade* entidade);
	void Printar();
};
