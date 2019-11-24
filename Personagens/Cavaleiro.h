#pragma once
#include "Jogador.h"

class Cavaleiro : public Jogador
{
public:
	Cavaleiro(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Cavaleiro();
	void printar(GerenciadorGrafico* grafico);
	void andar();
	void pular();
	void atacar();
};
