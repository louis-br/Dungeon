#pragma once
#include <vector>

namespace Entidades {
	class EntidadeFisica;
}

namespace Listas {
	class VetorEntidadeFisica
	{
	private:
		std::vector<Entidades::EntidadeFisica*> LEFs;
	public:
		VetorEntidadeFisica();
		~VetorEntidadeFisica();
		void empilharTras(Entidades::EntidadeFisica* entidade);
		void remover(Entidades::EntidadeFisica* entidade);
		int tamanho();
		Entidades::EntidadeFisica*& operator[](int indice);
	};
}