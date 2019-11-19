#include "GerenciadorFisico.h"


GerenciadorFisico::GerenciadorFisico() :
	gravidade(0, 10)
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
		sf::Vector2f distExtremoAB = extremoA - posB;
		sf::Vector2f distAextremoB = extremoB - posA;
		float direita = 0;
		int sentidoDireita = 0;
		if (distExtremoAB.x < distAextremoB.x) {
			direita = distExtremoAB.x;
			sentidoDireita = -1;
		}
		else {
			direita = distAextremoB.x;
			sentidoDireita = 1;
		}
		float baixo = 0;
		int sentidoBaixo = 0;
		if (distExtremoAB.y < distAextremoB.y) {
			baixo = distExtremoAB.y;
			sentidoBaixo = -1;
		}
		else {
			baixo = distAextremoB.y;
			sentidoBaixo = 1;
		}
		if (direita < baixo) {
			return sf::Vector2f(direita * sentidoDireita, 0);
		}
		else {
			return sf::Vector2f(0, baixo * sentidoBaixo);
		}
	}
	return sf::Vector2f(0, 0);
}

void GerenciadorFisico::executar(VetorEntidadeFisica& moveis, ListaEntidade& entidades) {
	//Lista<Entidade>::Elemento<Entidade>* atual = ListaEntidade
	float decorrido = relogio.getElapsedTime().asSeconds();
	relogio.restart();
	for (int i = 0; i < moveis.tamanho(); ++i) {
		EntidadeFisica* movel = moveis[i];
		sf::Vector2f aceleracao = movel->getAceleracao() + gravidade;
		sf::Vector2f velocidade = movel->getVelocidade() + aceleracao * decorrido;
		sf::Vector2f posicao = movel->getPosicao() + velocidade * decorrido + aceleracao * 0.5f * (decorrido * decorrido);
		//sf::Vector2f correcao = colidir(static_cast<Entidade*>(moveis[i]))
		Entidade* A = static_cast<Entidade*>(movel);
		Lista<Entidade>::Elemento<Entidade>* atual = entidades.getPrimeiro();
		while (atual != nullptr) {
			Entidade* B = atual->getElemento();
			if (A != B) {
				posicao += colidir(A, atual->getElemento());
			}
			atual = atual->getProximo();
		}
		movel->setVelocidade(velocidade);
		movel->setPosicao(posicao);
	}
}

GerenciadorFisico* GerenciadorFisico::instancia(nullptr);