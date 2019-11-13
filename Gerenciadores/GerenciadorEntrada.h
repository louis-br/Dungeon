#pragma once
#include <SFML/Graphics.hpp>

class GerenciadorEntrada
{ 
private:
	sf::RenderWindow* janela;
	static GerenciadorEntrada* instancia;
	GerenciadorEntrada(sf::RenderWindow* window = nullptr);
	~GerenciadorEntrada();
public:
	static GerenciadorEntrada* getInstancia();
	void setJanela(sf::RenderWindow* window);
	void Executar();
};
