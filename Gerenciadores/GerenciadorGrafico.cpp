#include "GerenciadorGrafico.h"
#include "../Entidade.h"

void GerenciadorGrafico::Inserir(Entidade* entidade)
{
	elementos.push_back(entidade);
}

void GerenciadorGrafico::Executar()
{
	GerenciadorGrafico& grafico = *this;
	for (iterador = elementos.begin(); iterador != elementos.end(); ++iterador) {
		(*iterador)->Apresentar(grafico);
	}
}
