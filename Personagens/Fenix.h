#pragma once
#include "Inimigo.h"
class Fenix : public Inimigo
{
private:
	class BolaDeFogo : public EntidadeFisica {
	private:
		bool visivel;
	public:
		BolaDeFogo(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
		~BolaDeFogo();
		Tipo getTipo();
		void colidiuCom(Tipo tipo);
		void printar(GerenciadorGrafico* grafico);
		void setVisivel(bool v);
	};
	BolaDeFogo* bolaDeFogo;
public:
	Fenix(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Fenix();
	void printar(GerenciadorGrafico* grafico);
};