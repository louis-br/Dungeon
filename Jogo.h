#pragma once
#include <SFML/Graphics.hpp>
#include "Gerenciadores/GerenciadorEntrada.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Jogo
{
private:
	sf::RenderWindow janela;
	GerenciadorEntrada entrada;
public:
	Jogo();
	~Jogo();
	void Executar();
};
