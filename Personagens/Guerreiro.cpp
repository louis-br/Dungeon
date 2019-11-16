#include "Guerreiro.h"

Guerreiro::Guerreiro(sf::Vector2f pos, ListaEntidade* lista) :
	Jogador(pos, sf::Vector2f(63, 75), lista),
	i(0)
{
	GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	grafico->CarregarTextura(textura, "Recursos/Personagens/Guerreiro.png");
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
}

Guerreiro::~Guerreiro() {

}

void Guerreiro::Printar(GerenciadorGrafico* grafico) {
	sprite.setTextureRect(sf::IntRect((i % 12) * 63, 0, 63, 75));
	++i;
	grafico->Desenhar(sprite);
}