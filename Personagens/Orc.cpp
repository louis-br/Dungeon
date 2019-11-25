#include "Orc.h"

Orc::Orc(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(36, 65), lista, vetor)
{
	sprite.setTexture(GerenciadorGrafico::getInstancia()
		 ->getTextura(GerenciadorGrafico::Texturas::Orc));
	sprite.setTextureRect(sf::IntRect(30, 7, 36, 65));
}

Orc::~Orc() {

}

void Orc::printar(GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	andar();
	grafico->desenhar(sprite);
}

void Orc::andar() {

}

//void Orc::colidiuCom(Tipo tipo) {

//}