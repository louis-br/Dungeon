#pragma once
#include "Jogador.h"
class Orc : public Jogador
{
private:
	//sf::Texture textura;
	sf::Sprite sprite;
public:
	Orc(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Orc();
	void printar(GerenciadorGrafico* grafico);
	void andar();
	//void colidiuCom(Tipo tipo);
};