#include "Estalactite.h"

Estalactite::Estalactite(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, tam, lista, vetor)
{
	setTextura(GerenciadorGrafico::Texturas::Estalactite);
}

Estalactite::~Estalactite() {

}

Estalactite::Tipo Estalactite::getTipo() {
	if (velocidade.y < 10) {
		return Tipo::Neutro;
	}
	else {
		return Tipo::Hostil;
	}
}

void Estalactite::colidiuCom(Tipo tipo) {
	if (tipo == Tipo::Jogador || tipo == Tipo::JogadorAtacando) {
		tamanho = sf::Vector2f(tamanho.x, 86);
	}
}

void Estalactite::printar(GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	grafico->desenhar(sprite);
}