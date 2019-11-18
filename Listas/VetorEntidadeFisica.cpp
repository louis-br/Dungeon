#include "VetorEntidadeFisica.h"
#include "../Entidades/EntidadeFisica.h"

VetorEntidadeFisica::VetorEntidadeFisica()
{

}

VetorEntidadeFisica::~VetorEntidadeFisica() {

}

void VetorEntidadeFisica::empilharTras(EntidadeFisica* entidade)
{
	LEFs.push_back(entidade);
}

int VetorEntidadeFisica::tamanho() {
	return LEFs.size();
}

EntidadeFisica*& VetorEntidadeFisica::operator[](int indice) {
	return LEFs[indice];
}