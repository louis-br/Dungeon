#include "Inimigo.h"

Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Personagem(pos, tam, lista, vetor)
{
	vidas = 1;
	potencialVelocidade = sf::Vector2f(0.f, 50.f);
	potencialAceleracao = sf::Vector2f(100.f, 0.f);
	velocidadeMaxima = sf::Vector2f(130.f, 50.f);
}

Inimigo::~Inimigo() {

}

Inimigo::Tipo Inimigo::getTipo() {
	return Tipo::Hostil;
}

void Inimigo::colidiuCom(Tipo tipo) {
	if (tipo == Tipo::JogadorAtacando && ultimoDano.getElapsedTime().asSeconds() > 1.f) {
		recebeuDano = true;
		--vidas;
		ultimoDano.restart();
	}
}