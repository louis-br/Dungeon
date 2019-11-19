#pragma once
#include <vector>

class EntidadeFisica;

class VetorEntidadeFisica
{
private:
	std::vector<EntidadeFisica*> LEFs;
public:
	VetorEntidadeFisica();
	~VetorEntidadeFisica();
	void empilharTras(EntidadeFisica* entidade);
	int tamanho();
	EntidadeFisica*& operator[](int indice);
};