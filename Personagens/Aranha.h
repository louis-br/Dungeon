#pragma once
#include "Inimigo.h"

class Aranha : public Inimigo
{
public:
	Aranha(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Aranha();
	void colidiuCom(Tipo tipo);
	void printar(GerenciadorGrafico* grafico);
	void andar();
};