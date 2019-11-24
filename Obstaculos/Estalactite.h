#pragma once
#include "../Entidades/EntidadeFisica.h"

class Estalactite : public EntidadeFisica
{
public:
	Estalactite(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Estalactite();
	Tipo getTipo();
	void colidiuCom(Tipo tipo);
	void printar(GerenciadorGrafico* grafico);
};

