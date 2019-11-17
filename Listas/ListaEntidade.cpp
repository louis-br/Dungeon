#include <iostream>
#include "ListaEntidade.h"
#include "../Entidades/Entidade.h"

ListaEntidade::ListaEntidade() :
	grafico(GerenciadorGrafico::getInstancia())
{

}

ListaEntidade::~ListaEntidade() {

}

void ListaEntidade::inserir(Entidade* entidade)
{
	elementos.push_back(entidade);
}

void ListaEntidade::printar()
{
	grafico->limpar();
	for (iterador = elementos.begin(); iterador != elementos.end(); ++iterador) {
		(*iterador)->printar(grafico);
	}
	grafico->atualizarTela();
}
