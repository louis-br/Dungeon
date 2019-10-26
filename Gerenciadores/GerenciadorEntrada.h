#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorEntrada
{ 
private:
	sf::RenderWindow* janela;
public:
	GerenciadorEntrada(sf::RenderWindow* window = nullptr);
	~GerenciadorEntrada();
	void Executar();
};

