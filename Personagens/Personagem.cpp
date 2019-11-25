#include "Personagem.h"

Personagens::Personagem::Personagem(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, tam, lista, vetor),
	potencialVelocidade(0, 0),
	potencialAceleracao(0, 0),
	relogio(),
	estado(Estado::Andando),
	quadroSprite(0),
	sentido(1),
	atualizar(true),
	vidas(4),
	coracao(Gerenciadores::GerenciadorGrafico::getInstancia()->getTextura(
			Gerenciadores::GerenciadorGrafico::Texturas::Coracao)),
	coracoes(coracao),
	recebeuDano(false)
{
	coracao.setRepeated(true);
	coracoes.setTexture(coracao);
	coracoes.setOrigin(0, 10);
}

Personagens::Personagem::~Personagem() {

}

void Personagens::Personagem::printarDano(Gerenciadores::GerenciadorGrafico* grafico, float tempo) {
	if (recebeuDano) {
		float dano = ultimoDano.getElapsedTime().asSeconds();
		if (dano < tempo) {
			if ((int)(dano * 8.f) % 2) {
				sprite.setColor(sf::Color(255, 255, 255));
			}
			else {
				sprite.setColor(sf::Color(255, 0, 0));
			}
		}
		else {
			recebeuDano = false;
		}
	}
}

void Personagens::Personagem::printarCoracoes(Gerenciadores::GerenciadorGrafico* grafico) {
	coracoes.setTextureRect(sf::IntRect(0, 0, 12 * vidas, 10));
	coracoes.setPosition(posicao);
	grafico->desenhar(coracoes);
}

void Personagens::Personagem::mover(sf::Vector2f direcao) {
	//direcao = sf::Vector2f(direcao.x, (float)(-(direcao.y < 0)));
	if (direcao.x != 0 && direcao.x != sentido) {
		atualizar = true;
		sentido = direcao.x;
	}
	if (estado == Estado::Atacando) {
		direcao = sf::Vector2f(direcao.x, 0);
	}
	else if (estado == Estado::Pulando) {
		direcao = sf::Vector2f(direcao.x, 0);
	} 
	else if (direcao.y < 0) {
		estado = Estado::Pulando;
		direcao = sf::Vector2f(direcao.x, -1);
	}
	else if (direcao.y > 0) {
		estado = Estado::Atacando;
		relogio.restart();
		direcao = sf::Vector2f(direcao.x, 0);
	}
	velocidade += sf::Vector2f(direcao.x * potencialVelocidade.x, direcao.y * potencialVelocidade.y);
	aceleracao = sf::Vector2f(direcao.x * potencialAceleracao.x, direcao.y * potencialAceleracao.y);
}