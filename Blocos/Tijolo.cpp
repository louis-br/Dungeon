#include "Tijolo.h"

Tijolo::Tijolo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista)
{
	GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	grafico->carregarTextura(textura, sf::IntRect(0, 80, 16, 16), "Recursos/Blocos/Tijolo.png");
	textura.setRepeated(true);
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setScale(2.f, 2.f);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tam/2.f)));
}

Tijolo::~Tijolo() {
	
}

Entidade::Tipo Tijolo::getTipo() {
	return Tipo::Hostil;
}

void Tijolo::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}
