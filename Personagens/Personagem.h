#pragma once
#include "../Entidades/EntidadeFisica.h"

namespace Personagens {
	class Personagem : public Entidades::EntidadeFisica
	{
	protected:
		enum Estado {
			Andando,
			Pulando,
			Atacando
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
		bool recebeuDano;
		sf::Texture coracao;
		sf::Sprite coracoes;
	public:
		Personagem(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~Personagem();
		void printarDano(Gerenciadores::GerenciadorGrafico* grafico, float tempo);
		void printarCoracoes(Gerenciadores::GerenciadorGrafico* grafico);
		void mover(sf::Vector2f direcao = sf::Vector2f(0, 0));
	};
}