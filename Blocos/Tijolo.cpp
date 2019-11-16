#include "Tijolo.h"

Tijolo::Tijolo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista)
{
	GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	grafico->CarregarTextura(textura, sf::IntRect(0, 80, 16, 16), "Recursos/Blocos/Tijolo.png");
	textura.setRepeated(true);
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tam)));
}

Tijolo::~Tijolo() {
	
}

void Tijolo::Printar(GerenciadorGrafico* grafico) {
	grafico->Desenhar(sprite);
}