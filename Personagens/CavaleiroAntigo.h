#pragma once
#include "Jogador.h"

class CavaleiroAntigo : public Jogador
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	CavaleiroAntigo(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~CavaleiroAntigo();
	void colidiuCom(Tipo tipo);
	void printar(GerenciadorGrafico* grafico);
	void andar();
};
