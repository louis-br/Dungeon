#include "Entidade.h"


Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	posicao(pos),
	tamanho(tam),
	atrito(1.f)
{
	if (lista != nullptr) {
		lista->empilharTras(this);
	}
}

/*Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, GerenciadorGrafico::Texturas tex, ListaEntidade* lista) {

}*/

Entidade::~Entidade() {

}

Entidade::Tipo Entidade::getTipo() {
	return Tipo::Neutro;
}

void Entidade::colidiuCom(Tipo tipo) {

}

void Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
}

sf::Vector2f Entidade::getPosicao() {
	return posicao;
}

void Entidade::setTamanho(sf::Vector2f pos) {
	tamanho = pos;
}

sf::Vector2f Entidade::getTamanho() {
	return tamanho;
}

void Entidade::setAtrito(float at) {
	atrito = at;
}

float Entidade::getAtrito() {
	return atrito;
}
