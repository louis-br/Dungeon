#include "Estalactite.h"

Obstaculos::Estalactite::Estalactite(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, tam, lista, vetor)
{
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Estalactite);
}

Obstaculos::Estalactite::~Estalactite() {

}

Obstaculos::Estalactite::Tipo Obstaculos::Estalactite::getTipo() {
	if (velocidade.y < 10) {
		return Tipo::Neutro;
	}
	else {
		return Tipo::Hostil;
	}
}

void Obstaculos::Estalactite::colidiuCom(Tipo tipo) {
	if (tipo == Tipo::Jogador || tipo == Tipo::JogadorAtacando) {
		tamanho = sf::Vector2f(tamanho.x, 86);
	}
}

void Obstaculos::Estalactite::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	grafico->desenhar(sprite);
}