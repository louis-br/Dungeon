#include "ListaEntidade.h"
#include "../Entidades/Entidade.h"

ListaEntidade::ListaEntidade() :
	grafico(GerenciadorGrafico::getInstancia()),
	LEs()
{

}

ListaEntidade::~ListaEntidade() {

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

void ListaEntidade::printar()
{
	grafico->limpar();
	Lista<Entidade>::Elemento<Entidade>* atual = LEs.getPrimeiro();
	while (atual != nullptr) {
		atual->getElemento()->printar(grafico);
		atual = atual->getProximo();
	}
	/*for (iterador = elementos.begin(); iterador != elementos.end(); ++iterador) {
		(*iterador)->printar(grafico);
	}*/
	grafico->atualizarTela();
}
