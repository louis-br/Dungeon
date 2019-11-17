#include "ListaEntidadeFisica.h"
#include "../Entidades/EntidadeFisica.h"

ListaEntidadeFisica::ListaEntidadeFisica()
{

}

ListaEntidadeFisica::~ListaEntidadeFisica() {

}

void ListaEntidadeFisica::inserir(EntidadeFisica* entidade)
{
	elementos.push_back(entidade);
}

list<EntidadeFisica*>* ListaEntidadeFisica::getLista() {
	return &elementos;
}