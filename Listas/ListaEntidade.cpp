#include "ListaEntidade.h"

ListaEntidade::ListaEntidade() :
	LEs()
{

}

ListaEntidade::~ListaEntidade() {

}

Lista<Entidade>* ListaEntidade::getListaEntidades() {
	return &LEs;
}