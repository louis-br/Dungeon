#pragma once
#include "Entidade.h"
#include "../Listas/VetorEntidadeFisica.h"

namespace Entidades {
	class EntidadeFisica : public Entidade
	{
	protected:
		sf::Vector2f velocidade;
		sf::Vector2f aceleracao;
		sf::Vector2f velocidadeMaxima;
		float atrito;
		bool excluido;
	public:
		EntidadeFisica(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::VetorEntidadeFisica* vetor = nullptr);
		EntidadeFisica(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Listas::VetorEntidadeFisica* vetor = nullptr);
		~EntidadeFisica();
		void setVelocidade(sf::Vector2f& vel);
		sf::Vector2f getVelocidade();
		void setAceleracao(sf::Vector2f& acel);
		sf::Vector2f getAceleracao();
		void setVelocidadeMaxima(sf::Vector2f& velMax);
		sf::Vector2f getVelocidadeMaxima();
		bool getExcluido();
	};
}