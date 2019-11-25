#include "Cavaleiro.h"
#include "math.h"

Cavaleiro::Cavaleiro(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(63, 77), lista, vetor)
{
	setTextura(GerenciadorGrafico::Texturas::Cavaleiro);
	sprite.setTextureRect(sf::IntRect((sentido > 0)*63, 0, -sentido*(int)(tamanho.x), (int)(tamanho.y)));
}

Cavaleiro::~Cavaleiro() {

}

void Cavaleiro::printar(GerenciadorGrafico* grafico) {
	if (posicao.y > 800) {
		posicao = sf::Vector2f(0, 0);
		vidas = 3;
	}
	printarCoracoes(grafico);
	printarDano(grafico, 5.f);
	sprite.setPosition(posicao);
	switch(estado) {
	case (Estado::Andando):
		andar();
		break;
	case (Estado::Pulando):
		pular();
		break;
	case (Estado::Atacando):
		atacar();
		break;
	default:
		break;
	}
	atualizar = false;
	grafico->desenhar(sprite);
}

void Cavaleiro::andar() {
	int quadros = (int)((relogio.getElapsedTime().asSeconds() * abs(velocidade.x)) / (tamanho.x) * 11.f);
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
	int quadro = (int)((velocidade.y + potencialVelocidade.y * 0.5f)/(potencialVelocidade.y) * 8.f);
	quadro = std::max(std::min(quadro, 8), 0);
	sprite.setTextureRect(sf::IntRect((quadro + (sentido > 0)) * 75, 77, -sentido * 75, 102));
}

void Cavaleiro::atacar() {
	int quadro = (int)(relogio.getElapsedTime().asSeconds() * 2.f * 5.f);
	quadro = std::min(quadro, 5);
	sprite.move(-32.5, -26);
	//tamanho = sf::Vector2f(128, 106);
	sprite.setTextureRect(sf::IntRect((quadro + (sentido > 0)) * 128, 179, -sentido * 128, 106));
	if (relogio.getElapsedTime().asSeconds() > 0.5f) {
		estado = Estado::Pulando;
	}
}
