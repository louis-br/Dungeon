#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class GerenciadorGrafico
{
private:
	sf::RenderWindow* janela;
	static GerenciadorGrafico* instancia;
	GerenciadorGrafico();
	~GerenciadorGrafico();
public:
	static GerenciadorGrafico* getInstancia();
	void setJanela(sf::RenderWindow* window);
	void limpar();
	void desenhar(sf::Drawable& forma);
	void atualizarTela();
	void carregarFonte(sf::Font& fonte, const std::string& arquivo);
	void carregarTextura(sf::Texture& textura, const std::string& arquivo);
	void carregarTextura(sf::Texture& textura, sf::IntRect area, const std::string& arquivo);
};