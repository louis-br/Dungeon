#include "Entidade.h"

Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, GerenciadorGrafico* grafico) :
	posicao(pos),
	tamanho(tam)
{
	if (grafico != nullptr) {
		grafico->Inserir(this);
	}
}

Entidade::~Entidade() {

}
