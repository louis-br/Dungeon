#include "VetorEntidadeFisica.h"
#include "../Entidades/EntidadeFisica.h"

VetorEntidadeFisica::VetorEntidadeFisica()
{

}

VetorEntidadeFisica::~VetorEntidadeFisica() {
	for (int i = 0; i < LEFs.size(); ++i) {
		delete LEFs[i];
	}
	LEFs.clear();
}

void VetorEntidadeFisica::empilharTras(EntidadeFisica* entidade)
{
	LEFs.push_back(entidade);
}

void VetorEntidadeFisica::remover(EntidadeFisica* entidade) {
	for (int i = 0; i < LEFs.size(); ++i) {
		if (LEFs[i] == entidade) {
			LEFs.erase(LEFs.begin() + i);
		}
	}
}

int VetorEntidadeFisica::tamanho() {
	return LEFs.size();
}

EntidadeFisica*& VetorEntidadeFisica::operator[](int indice) {
	return LEFs[indice];
}