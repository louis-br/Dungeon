#include "VetorEntidadeFisica.h"
#include "../Entidades/EntidadeFisica.h"

Listas::VetorEntidadeFisica::VetorEntidadeFisica()
{

}

Listas::VetorEntidadeFisica::~VetorEntidadeFisica() {
	for (int i = 0; i < LEFs.size(); ++i) {
		delete LEFs[i];
	}
	LEFs.clear();
}

void Listas::VetorEntidadeFisica::empilharTras(Entidades::EntidadeFisica* entidade)
{
	LEFs.push_back(entidade);
}

void Listas::VetorEntidadeFisica::remover(Entidades::EntidadeFisica* entidade) {
	for (int i = 0; i < LEFs.size(); ++i) {
		if (LEFs[i] == entidade) {
			LEFs.erase(LEFs.begin() + i);
		}
	}
}

int Listas::VetorEntidadeFisica::tamanho() {
	return LEFs.size();
}

Entidades::EntidadeFisica*& Listas::VetorEntidadeFisica::operator[](int indice) {
	return LEFs[indice];
}