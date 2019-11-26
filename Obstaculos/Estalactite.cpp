#include "Estalactite.h"

Obstaculos::Estalactite::Estalactite(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	Obstaculo(pos, tam, lista),
	EntidadeFisica(pos, tam, vetor)
{
	Obstaculo::setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Estalactite);
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
		EntidadeFisica::tamanho = sf::Vector2f(EntidadeFisica::tamanho.x, 86);
	}
}

void Obstaculos::Estalactite::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	Obstaculo::sprite.setPosition(Obstaculo::posicao);
	grafico->desenhar(Obstaculo::sprite);
}