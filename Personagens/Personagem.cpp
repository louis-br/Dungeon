#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, tam, lista, vetor),
	potencialVelocidade(0, 0),
	potencialAceleracao(0, 0),
	relogio(),
	estado(Estado::Andando),
	quadroSprite(0)
{

}

Personagem::~Personagem() {

}

void Personagem::mover(sf::Vector2f direcao) {
	if (estado == Estado::Pulando) {
		direcao = sf::Vector2f(direcao.x, 0);
	} else if (direcao.y < 0) {
		estado = Estado::Pulando;
		direcao = sf::Vector2f(direcao.x, -1);
	}
	velocidade += sf::Vector2f(direcao.x * potencialVelocidade.x, direcao.y * potencialVelocidade.y);
	aceleracao = sf::Vector2f(direcao.x * potencialAceleracao.x, direcao.y * potencialAceleracao.y);
}