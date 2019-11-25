#include "Entidade.h"


Entidades::Entidade::Entidade(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista) :
	posicao(pos),
	tamanho(tam),
	atrito(1.f),
	textura(),
	sprite(textura)
{
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
	if (lista != nullptr) {
		lista->empilharTras(this);
	}
}

Entidades::Entidade::~Entidade() {

}

Entidades::Entidade::Tipo Entidades::Entidade::getTipo() {
	return Tipo::Neutro;
}

void Entidades::Entidade::colidiuCom(Tipo tipo) {

}

void Entidades::Entidade::setTextura(Gerenciadores::GerenciadorGrafico::Texturas tex) {
	textura = Gerenciadores::GerenciadorGrafico::getInstancia()->getTextura(tex);
}

void Entidades::Entidade::setPosicao(sf::Vector2f pos) {
	posicao = pos;
}

sf::Vector2f Entidades::Entidade::getPosicao() {
	return posicao;
}

void Entidades::Entidade::setTamanho(sf::Vector2f pos) {
	tamanho = pos;
}

sf::Vector2f Entidades::Entidade::getTamanho() {
	return tamanho;
}

void Entidades::Entidade::setAtrito(float at) {
	atrito = at;
}

float Entidades::Entidade::getAtrito() {
	return atrito;
}
