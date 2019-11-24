#pragma once
#include "Inimigo.h"

class Anao : public Inimigo
{
public:
	Anao(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Anao();
	void printar(GerenciadorGrafico* grafico);
	void andar();
	//void colidiuCom(Tipo tipo);
};