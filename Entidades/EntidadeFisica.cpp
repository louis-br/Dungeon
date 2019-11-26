#include "EntidadeFisica.h"

Entidades::EntidadeFisica::EntidadeFisica(sf::Vector2f pos, sf::Vector2f tam, Listas::VetorEntidadeFisica* vetor) :
	Entidade(pos, tam),
	velocidade(0, 0),
	aceleracao(0, 0),
	velocidadeMaxima(0, 0),
	atrito(0),
	excluido(false)
{
	if (vetor != nullptr) {
		vetor->empilharTras(this);
	}
}

Entidades::EntidadeFisica::EntidadeFisica(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	Entidade(pos, tam, lista),
	velocidade(0, 0),
	aceleracao(0, 0),
	velocidadeMaxima(0, 0),
	atrito(0),
	excluido(false)
{
	if (vetor != nullptr) {
		vetor->empilharTras(this);
	}
}

Entidades::EntidadeFisica::~EntidadeFisica() {

}

void Entidades::EntidadeFisica::setVelocidade(sf::Vector2f& vel) {
	velocidade = vel;
}

sf::Vector2f Entidades::EntidadeFisica::getVelocidade() {
	return velocidade;
}

void Entidades::EntidadeFisica::setAceleracao(sf::Vector2f& acel) {
	aceleracao = acel;
}

sf::Vector2f Entidades::EntidadeFisica::getAceleracao() {
	return aceleracao;
}

void Entidades::EntidadeFisica::setVelocidadeMaxima(sf::Vector2f& velMax) {
	velocidadeMaxima = velMax;
}

sf::Vector2f Entidades::EntidadeFisica::getVelocidadeMaxima() {
	return velocidadeMaxima;
}

bool Entidades::EntidadeFisica::getExcluido() {
	return excluido;
}