#include "ListaEntidade.h"
#include "../Entidades/Entidade.h"

ListaEntidade::ListaEntidade() :
	grafico(GerenciadorGrafico::getInstancia()),
	LEs()
{

}

ListaEntidade::~ListaEntidade() {
	Lista<Entidade>::Elemento<Entidade>* atual = LEs.getPrimeiro();
	while (atual != nullptr) {
		Lista<Entidade>::Elemento<Entidade>* proximo = atual->getProximo();
		delete atual;
		atual = proximo;
	}
}

Lista<Entidade>::Elemento<Entidade>* ListaEntidade::getPrimeiro() {
	return LEs.getPrimeiro();
}

Lista<Entidade>::Elemento<Entidade>* ListaEntidade::getUltimo() {
	return LEs.getUltimo();
}

void ListaEntidade::empilharTras(Entidade* entidade)
{
	LEs.empilharTras(entidade);
}

void ListaEntidade::remover(Entidade* entidade) {
	LEs.remover(entidade);
}

void ListaEntidade::printar() {
	Lista<Entidade>::Elemento<Entidade>* atual = LEs.getPrimeiro();
	while (atual != nullptr) {
		atual->getElemento()->printar(grafico);
		atual = atual->getProximo();
	}
}
