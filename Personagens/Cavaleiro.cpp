#include "Cavaleiro.h"

Cavaleiro::Cavaleiro(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(36, 65), lista, vetor)
{
	sprite.setTexture(GerenciadorGrafico::getInstancia()
		 ->getTextura(GerenciadorGrafico::Texturas::Cavaleiro));
	sprite.setTextureRect(sf::IntRect(30, 7, 36, 65));
}

Cavaleiro::~Cavaleiro() {

}

void Cavaleiro::printar(GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	andar();
	grafico->desenhar(sprite);
}

void Cavaleiro::andar() {

}

//void Cavaleiro::colidiuCom(Tipo tipo) {

//}