#include "Plataforma.h"

Plataforma::Plataforma(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, GerenciadorGrafico::Texturas tex) :
	Entidade(pos, tam, lista),
	textura(GerenciadorGrafico::getInstancia()->getTextura(
			tex))
{
	//grafico->carregarTextura(textura, sf::IntRect(0, 80, 16, 16), "Recursos/Blocos/Plataforma.png");
	textura.setRepeated(true);
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
	//sprite.setScale(2.f, 2.f);
	//sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tam/2.f)));
}

Plataforma::~Plataforma() {
	
}

Entidade::Tipo Plataforma::getTipo() {
	return Tipo::Hostil;
}

void Plataforma::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}
