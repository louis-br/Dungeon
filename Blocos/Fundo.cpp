#include "Fundo.h"

Fundo::Fundo(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista),
	textura(GerenciadorGrafico::getInstancia()->getTextura(
		GerenciadorGrafico::Texturas::Floresta))
{
	//grafico->carregarTextura(textura, sf::IntRect(0, 80, 16, 16), "Recursos/Blocos/Tijolo.png");
	textura.setRepeated(true);
	sprite = sf::Sprite(textura);
	sprite.setPosition(pos);
	sprite.setTextureRect(sf::IntRect(static_cast<sf::Vector2i>(posicao), static_cast<sf::Vector2i>(tamanho)));
	tamanho = sf::Vector2f(0, 0);
	//sprite.setScale(2.f, 2.f);
	//sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tam/2.f)));
}

Fundo::~Fundo() {

}

void Fundo::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}
