#include "Entidade.h"


Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	posicao(pos),
	tamanho(tam)
{
	if (lista != nullptr) {
		lista->empilharTras(this);
	}
}

Entidade::~Entidade() {

}

Entidade::Tipo Entidade::getTipo() {
	return Tipo::Neutro;
}

void Entidade::colidiuCom(Tipo tipo) {

}

sf::Vector2f Entidade::getPosicao() {
	return posicao;
}

sf::Vector2f Entidade::getTamanho() {
	return tamanho;
}

void Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
}

void Entidade::setTamanho(sf::Vector2f pos) {
	tamanho = pos;
}
