#include "Cavaleiro.h"

Cavaleiro::Cavaleiro(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(63, 77), lista, vetor)
{
	//GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	//grafico->carregarTextura(textura, "Recursos/Personagens/Cavaleiro.png");
	textura = GerenciadorGrafico::getInstancia()->getTextura(
			  GerenciadorGrafico::Texturas::Cavaleiro);
	sprite = sf::Sprite(textura);
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i((sentido > 0)*63, 0), sf::Vector2i(-sentido*tamanho.x, tamanho.y)));
	//sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
	sf::Vector2f v = sf::Vector2f(5.f, 0.f);
	setVelocidade(v);
}

Cavaleiro::~Cavaleiro() {

}

/*void Cavaleiro::colidiuCom(Entidade* entidade) {
	std::cout << "Cavaleiro colidiu!\n";
	//colidiuCom(dynamic_cast<void*>(entidade));
	Tijolo* tijolo = dynamic_cast<Tijolo*>(entidade);
	if (tijolo != nullptr) {
		colidiuCom(tijolo);
	}
}

void Cavaleiro::colidiuCom(Tijolo* tijolo) {
	std::cout << "Tijolo!\n";
}*/

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
	//sprite.setTextureRect(sf::IntRect((i % 12) * 63, 0, 63, 77));
	//++i;
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
	int quadro = (velocidade.y + potencialVelocidade.y * 0.5f)/(2*potencialVelocidade.y) * 1.25 * 8;
	quadro = fmax(fmin(quadro, 8), 0);	
	sprite.setTextureRect(sf::IntRect((quadro + (sentido > 0)) * 75, 77, -sentido * 75, 102));
}
