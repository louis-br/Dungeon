#include "Plataforma.h"

Plataformas::Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Gerenciadores::GerenciadorGrafico::Texturas tex) :
	Entidade(pos, tam, lista)
{
	setTextura(tex);
	textura.setRepeated(true);
}

Plataformas::Plataforma::~Plataforma() {
	
}

void Plataformas::Plataforma::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}
