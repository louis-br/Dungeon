#pragma once
#include "Jogador.h"
#include "../Blocos/Tijolo.h"

class Guerreiro : public Jogador
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	Guerreiro(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Guerreiro();
	void colidiuCom(Tipo tipo);
	void printar(GerenciadorGrafico* grafico);
	void andar();
};
