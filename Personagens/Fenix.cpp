#include "Fenix.h"

Personagens::Fenix::Fenix(sf::Vector2f pos, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	Inimigo(pos, sf::Vector2f(159, 214), lista, vetor),
	bolaDeFogo(new BolaDeFogo(pos, lista, vetor))
{
	vidas = 3;
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Fenix);
}

Personagens::Fenix::~Fenix() {

}

void Personagens::Fenix::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	printarCoracoes(grafico);
	printarDano(grafico, 1.f);
	float decorrido = relogio.getElapsedTime().asSeconds();
	if (decorrido > 8.f) {
		bolaDeFogo->setVisivel(true);
		bolaDeFogo->setPosicao(posicao + tamanho* 0.5f + sf::Vector2f((float)sentido * 85, 0));
		sf::Vector2f vel = sf::Vector2f(velocidade.x + 100.f * (float)sentido, 10.f);
		bolaDeFogo->setVelocidade(vel);
		relogio.restart();
	}
	sentido = (int)(decorrido * 0.25f) % 2 == 0;
	if (!sentido) {
		sentido = -1;
	}
	mover(sf::Vector2f(sentido, -1));
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect((sentido < 0) * 159, 0, sentido * 159, 214));
	grafico->desenhar(sprite);
}

Personagens::Fenix::BolaDeFogo::BolaDeFogo(sf::Vector2f pos, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
	EntidadeFisica(pos, sf::Vector2f(16, 15), lista, vetor),
	visivel(false)
{
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::BolaDeFogo);
}

Personagens::Fenix::BolaDeFogo::~BolaDeFogo() {

}

Personagens::Fenix::BolaDeFogo::Tipo Personagens::Fenix::BolaDeFogo::getTipo() {
	if (visivel) {
		return Tipo::Hostil;
	}
	else {
		return Tipo::Neutro;
	}
}

void Personagens::Fenix::BolaDeFogo::colidiuCom(Tipo tipo) {
	if (tipo == Tipo::Neutro) {
		visivel = false;
	}
}

void Personagens::Fenix::BolaDeFogo::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	if (visivel) {
		grafico->desenhar(sprite);
	}
}

void Personagens::Fenix::BolaDeFogo::setVisivel(bool v) {
	visivel = v;
}