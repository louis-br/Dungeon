#pragma once
#include "Entidade.h"
#include "../Listas/VetorEntidadeFisica.h"

class EntidadeFisica : public Entidade
{
protected:
	sf::Vector2f velocidade;
	sf::Vector2f aceleracao;
	sf::Vector2f velocidadeMaxima;
public:
	EntidadeFisica(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~EntidadeFisica();
	void setVelocidade(sf::Vector2f& vel);
	sf::Vector2f getVelocidade();
	void setAceleracao(sf::Vector2f& acel);
	sf::Vector2f getAceleracao();
	void setVelocidadeMaxima(sf::Vector2f& velMax);
	sf::Vector2f getVelocidadeMaxima();
};

