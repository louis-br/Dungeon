#include "CavaleiroAntigo.h"

CavaleiroAntigo::CavaleiroAntigo(sf::Vector2f pos, ListaEntidade* lista, VetorEntidadeFisica* vetor) :
	Jogador(pos, sf::Vector2f(63, 77), lista, vetor)
{
	potencialVelocidade = sf::Vector2f(0, 50);
	potencialAceleracao = sf::Vector2f(100, 0);
	//GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	//grafico->carregarTextura(textura, "Recursos/Personagens/CavaleiroAntigo.png");
	sprite = sf::Sprite(textura);
	sprite.setPosition(posicao);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), static_cast<sf::Vector2i>(tamanho)));
	sf::Vector2f v = sf::Vector2f(5.f, 0.f);
	setVelocidade(v);
}

CavaleiroAntigo::~CavaleiroAntigo() {

}

/*void CavaleiroAntigo::colidiuCom(Entidade* entidade) {
	std::cout << "CavaleiroAntigo colidiu!\n";
	//colidiuCom(dynamic_cast<void*>(entidade));
	Tijolo* tijolo = dynamic_cast<Tijolo*>(entidade);
	if (tijolo != nullptr) {
		colidiuCom(tijolo);
	}
}

void CavaleiroAntigo::colidiuCom(Tijolo* tijolo) {
	std::cout << "Tijolo!\n";
}*/

void CavaleiroAntigo::colidiuCom(Tipo tipo) {
	//std::cout << "Cavaleiro colidiu com " << tipo << '\n';
}

void CavaleiroAntigo::printar(GerenciadorGrafico* grafico) {
	sprite.setPosition(posicao);
	switch(estado) {
	case (Estado::Ocioso):
		break;
	case (Estado::Andando):
		andar();
		break;
	case (Estado::Pulando):
		break;
	default:
		break;
	}
	//sprite.setTextureRect(sf::IntRect((i % 12) * 63, 0, 63, 77));
	//++i;
	grafico->desenhar(sprite);
}

void CavaleiroAntigo::andar() {
	//velocidade = sf::Vector2f(5, 0);
	//aceleracao = sf::Vector2f(0, 100);
	int quadros = 11 * (relogio.getElapsedTime().asSeconds() * velocidade.x) / (tamanho.x);
	if (quadros > 0) {
		relogio.restart();
		quadroSprite += quadros;
		quadroSprite %= 12;
		sprite.setTextureRect(sf::IntRect(quadroSprite * 63, 0, 63, 77));
	}
}
