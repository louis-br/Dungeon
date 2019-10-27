#pragma once
#include "Entidade.h"

class Menu : public Entidade
{
private:
	sf::CircleShape forma;
public:
	Menu(GerenciadorGrafico* grafico);
	~Menu();
	void Executar();
	void CriarGraficos();
	void Apresentar(GerenciadorGrafico& grafico);
};