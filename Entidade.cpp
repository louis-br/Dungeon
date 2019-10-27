#include "Entidade.h"

Entidade::Entidade(int x, int y, unsigned largura, unsigned altura, GerenciadorGrafico* grafico) :
	posicao(x, y),
	tamanho(largura, altura)
{
	if (grafico != nullptr) {
		grafico->Inserir(this);
	}
}

Entidade::~Entidade() {

}
