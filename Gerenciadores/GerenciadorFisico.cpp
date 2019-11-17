#include "GerenciadorFisico.h"


GerenciadorFisico::GerenciadorFisico() :
	entidades(nullptr)
{

}

GerenciadorFisico::~GerenciadorFisico() {

}

GerenciadorFisico* GerenciadorFisico::getInstancia() {
	if (instancia == nullptr) {
		instancia = new GerenciadorFisico();
	}
	return instancia;
}

sf::Vector2f GerenciadorFisico::colidir(Entidade* A, Entidade* B) {
	sf::Vector2f posA = A->getPosicao();
	sf::Vector2f extremoA = posA + A->getTamanho();
	sf::Vector2f posB = B->getPosicao();
	sf::Vector2f extremoB = posB + B->getTamanho();
	if (extremoA.x > posB.x && extremoA.y > posB.y &&
		posA.x < extremoB.x && posA.y < extremoB.y)
	{
		sf::Vector2f distAB = posA - posB;
		sf::Vector2f distAextremoB = extremoB - posA;
		float direita = 0;
		int sentidoDireita = 0;
		if (distAB.x > distAextremoB.x) {
			direita = distAB.x;
			sentidoDireita = -1;
		}
		else {
			direita = distAextremoB.x;
			sentidoDireita = 1;
		}
		float baixo = 0;
		int sentidoBaixo = 0;
		if (distAB.y > distAextremoB.y) {
			baixo = distAB.y;
			sentidoBaixo = -1;
		}
		else {
			baixo = distAextremoB.y;
			sentidoBaixo = 1;
		}
		if (direita > baixo) {
			return sf::Vector2f(direita * sentidoDireita, 0);
		}
		else {
			return sf::Vector2f(0, baixo * sentidoBaixo);
		}
	}
	return sf::Vector2f(0, 0);
}

void GerenciadorFisico::executar() {
	for (std::list<EntidadeFisica>::iterator i = moveis.begin(); i != moveis.end(); ++i) {
		sf::Vector2f aceleracao = i->getAceleracao();
		sf::Vector2f velocidade = i->getVelocidade() + aceleracao * decorrido;
		sf::Vector2i posicao = i->getPosicao()
			+ static_cast<sf::Vector2i>(velocidade * decorrido)
			+ static_cast<sf::Vector2i>(aceleracao * 0.5f * decorrido));
			sf::Vector2i tamanho = i->getTamanho();
			bool colisao = false;
			sf::Vector2f correcaoTotal(0, 0);
			for (std::list<EntidadeFisica>::iterator j = lista.begin(); j != lista.end(); ++j) {
				sf::Vector2i jpos = j->getPosicao();
				sf::Vector2i jtam = j->getTamanho();
				sf::Vector2i correcao(0, 0);
				sf::Vector2i diferenca = posicao + tamanho;
			}
	}
}

GerenciadorFisico* GerenciadorFisico::instancia(nullptr);