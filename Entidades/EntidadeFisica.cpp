#include "EntidadeFisica.h"

EntidadeFisica::EntidadeFisica(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Entidade(pos, tam, lista),
	velocidade(0, 0),
	aceleracao(0, 0),
	velocidadeMaxima(0, 0)
{
	if (vetor != nullptr) {
		vetor->empilharTras(this);
	}
}

EntidadeFisica::~EntidadeFisica() {

}

void EntidadeFisica::setVelocidade(sf::Vector2f& vel) {
	velocidade = vel;
}

sf::Vector2f EntidadeFisica::getVelocidade() {
	return velocidade;
}

void EntidadeFisica::setAceleracao(sf::Vector2f& acel) {
	aceleracao = acel;
}

sf::Vector2f EntidadeFisica::getAceleracao() {
	return aceleracao;
}

void EntidadeFisica::setVelocidadeMaxima(sf::Vector2f& velMax) {
	velocidadeMaxima = velMax;
}

sf::Vector2f EntidadeFisica::getVelocidadeMaxima() {
	return velocidadeMaxima;
}