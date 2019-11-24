#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Personagem(pos, tam, lista, vetor)
{
	potencialVelocidade = sf::Vector2f(0.f, 11.f);
	potencialAceleracao = sf::Vector2f(100.f, 0.f);
	velocidadeMaxima = sf::Vector2f(130.f, 0.f);
}

Inimigo::~Inimigo() {

}

Inimigo::Tipo Inimigo::getTipo() {
	return Tipo::Hostil;
}