#include "Obstaculo.h"

Obstaculos::Obstaculo::Obstaculo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista) :
	Entidade(pos, tam, lista)
{

}

Obstaculos::Obstaculo::~Obstaculo() {

}

void Obstaculos::Obstaculo::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}