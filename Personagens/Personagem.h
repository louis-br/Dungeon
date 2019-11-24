#pragma once
#include "../Entidades/EntidadeFisica.h"
class Personagem : public EntidadeFisica
{
protected:
	enum Estado {
		Ocioso,
		Andando,
		Pulando
	};
	sf::Vector2f potencialVelocidade;
	sf::Vector2f potencialAceleracao;
	sf::Clock relogio;
	sf::Clock ultimoDano;
	Estado estado;
	int quadroSprite;
	int sentido;
	bool atualizar;
	int vidas;
	sf::Texture coracao;
	sf::Sprite coracoes;
public:
	Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Personagem();
	void printarCoracoes(GerenciadorGrafico* grafico);
	void mover(sf::Vector2f direcao = sf::Vector2f(0, 0));
};