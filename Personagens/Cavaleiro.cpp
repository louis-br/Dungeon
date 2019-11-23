#include "Cavaleiro.h"
#include "math.h"

Cavaleiro::Cavaleiro(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(63, 77), lista, vetor)
{
	textura = GerenciadorGrafico::getInstancia()->getTextura(
			  GerenciadorGrafico::Texturas::Cavaleiro);
	sprite = sf::Sprite(textura);
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i((sentido > 0)*63, 0), sf::Vector2i(-sentido*tamanho.x, tamanho.y)));
}

Cavaleiro::~Cavaleiro() {

}

void Cavaleiro::printar(GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	switch(estado) {
	case (Estado::Andando):
		andar();
		break;
	case (Estado::Pulando):
		pular();
		break;
	default:
		break;
	}
	atualizar = false;
	grafico->desenhar(sprite);
}

void Cavaleiro::andar() {
	int quadros = 11 * (relogio.getElapsedTime().asSeconds() * abs(velocidade.x)) / (tamanho.x);
	if (quadros > 0) {
		relogio.restart();
		atualizar = true;
	}
	if (atualizar) {
		quadroSprite += quadros;
		quadroSprite %= 12;
		sprite.setTextureRect(sf::IntRect((quadroSprite + (sentido > 0)) * 63, 0, -sentido*63, 77));
	}
}

void Cavaleiro::pular() {
	sprite.move(sf::Vector2f(-6, -12));
	int quadro = (velocidade.y + potencialVelocidade.y * 0.5f)/(potencialVelocidade.y) * 8;
	quadro = fmax(fmin(quadro, 8), 0);	
	sprite.setTextureRect(sf::IntRect((quadro + (sentido > 0)) * 75, 77, -sentido * 75, 102));
}
