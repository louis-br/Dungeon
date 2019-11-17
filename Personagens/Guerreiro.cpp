#include "Guerreiro.h"

Guerreiro::Guerreiro(sf::Vector2f pos, ListaEntidade* lista) :
	Jogador(pos, sf::Vector2f(63, 77), lista)
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
	switch(estado) {
	case (Estado::Ocioso):
		break;
	case (Estado::Andando):
		Andar();
		break;
	case (Estado::Pulando):
		break;
	default:
		break;
	}
	//sprite.setTextureRect(sf::IntRect((i % 12) * 63, 0, 63, 77));
	//++i;
	grafico->Desenhar(sprite);
}

void Guerreiro::Andar() {
	velocidade = sf::Vector2f(63, 0);
	int quadros = 11 * (relogio.getElapsedTime().asSeconds() * velocidade.x) / (tamanho.x);
	if (quadros > 0) {
		relogio.restart();
		quadroSprite += quadros;
		quadroSprite %= 12;
		sprite.setTextureRect(sf::IntRect(quadroSprite * 63, 0, 63, 77));
	}
}