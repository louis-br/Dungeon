#include <iostream>
#include "ListaEntidade.h"
#include "../Entidade.h"

ListaEntidade::ListaEntidade() :
	grafico(GerenciadorGrafico::getInstancia())
{

}

ListaEntidade::~ListaEntidade() {

}

void ListaEntidade::Inserir(Entidade* entidade)
{
	elementos.push_back(entidade);
}

void ListaEntidade::Printar()
{
	grafico->Limpar();
	for (iterador = elementos.begin(); iterador != elementos.end(); ++iterador) {
		(*iterador)->Printar(grafico);
	}
	grafico->AtualizarTela();
}
