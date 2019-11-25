#pragma once
#include "Inimigo.h"
class Fenix : public Inimigo
{
private:
	class BolaDeFogo : public EntidadeFisica {
	public:
		BolaDeFogo();
		~BolaDeFogo();
		Tipo getTipo();
		void colidiuCom(Tipo tipo);
		void printar(GerenciadorGrafico* grafico);
	};
	BolaDeFogo bolaDeFogo;
public:
	Fenix(sf::Vector2f pos = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr, VetorEntidadeFisica* vetor = nullptr);
	~Fenix();
	void colidiuCom(Tipo tipo);
	void printar(GerenciadorGrafico* grafico);
	void andar();
};