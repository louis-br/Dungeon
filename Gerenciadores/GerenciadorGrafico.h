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
	void Limpar();
	void Desenhar(sf::Drawable& forma);
	void AtualizarTela();
	void CarregarFonte(sf::Font& fonte, const std::string& arquivo);
	void CarregarTextura(sf::Texture& textura, const std::string& arquivo);
	void CarregarTextura(sf::Texture& textura, sf::IntRect area, const std::string& arquivo);
};