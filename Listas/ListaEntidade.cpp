#include "ListaEntidade.h"
#include "../Entidades/Entidade.h"

Listas::ListaEntidade::ListaEntidade() :
	grafico(Gerenciadores::GerenciadorGrafico::getInstancia()),
	LEs()
{

}

Listas::ListaEntidade::~ListaEntidade() {
	Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual = LEs.getPrimeiro();
	while (atual != nullptr) {
		Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* proximo = atual->getProximo();
		delete atual;
		atual = proximo;
	}
}

Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* Listas::ListaEntidade::getPrimeiro() {
	return LEs.getPrimeiro();
}

Listas::Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* Listas::ListaEntidade::getUltimo() {
	return LEs.getUltimo();
}

void Listas::ListaEntidade::empilharTras(Entidades::Entidade* entidade)
{
	LEs.empilharTras(entidade);
}

void Listas::ListaEntidade::remover(Entidades::Entidade* entidade) {
	LEs.remover(entidade);
}

void Listas::ListaEntidade::printar() {
	Lista<Entidades::Entidade>::Elemento<Entidades::Entidade>* atual = LEs.getPrimeiro();
	while (atual != nullptr) {
		atual->getElemento()->printar(grafico);
		atual = atual->getProximo();
	}
}
