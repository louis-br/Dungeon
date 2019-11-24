#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, GerenciadorGrafico::Texturas tex) :
	Entidade(pos, tam, lista)
{
	setTextura(tex);
	textura.setRepeated(true);
}

Plataforma::~Plataforma() {
	
}

void Plataforma::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}
