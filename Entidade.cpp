#include "Entidade.h"

Entidade::Entidade(int x, int y, unsigned largura, unsigned altura) :
	posicao(x, y),
	tamanho(largura, altura)
{
	//GerenciadorGrafico.Inserir(this);
}

Entidade::~Entidade() {

}