#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	EntidadeFisica(pos, tam, lista),
	potencialAceleracao(0, 0),
	potencialVelocidade(0, 0),
	relogio(),
	estado(Estado::Andando),
	quadroSprite(0)
{

}

Personagem::~Personagem() {

}

void Personagem::Mover(sf::Vector2f direcao) {
	direcao = sf::Vector2f(direcao.x, direcao.y > 0);
	velocidade += sf::Vector2f(direcao.x * potencialVelocidade.x, direcao.y * potencialVelocidade.y);
	aceleracao = sf::Vector2f(direcao.x * potencialAceleracao.x, direcao.y * potencialAceleracao.y);
}