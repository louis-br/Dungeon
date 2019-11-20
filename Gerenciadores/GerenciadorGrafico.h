#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Listas/MapaRecursos.h"

class GerenciadorGrafico
{
private:
	sf::RenderWindow* janela;
	static GerenciadorGrafico* instancia;
	GerenciadorGrafico();
	~GerenciadorGrafico();
public:
	enum Texturas {
		Tijolo,
		Grama,
		PlataformaGrama,
		PlataformaGramaPequenaBaixa,
		PlataformaGramaPequenaMedia,
		PlataformaGramaPequenaGrande,
		PlataformaGramaMediaBaixa,
		Lava,
		Escada,
		Cavaleiro,
		Orc,
		Aranha,
		Floresta,
		Estalactite,
		TeiaDeAranha
	};
private:
	MapaRecursos<GerenciadorGrafico::Texturas, sf::Texture> mapaTexturas;
public:
	static GerenciadorGrafico* getInstancia();
	void setJanela(sf::RenderWindow* window);
	void limpar();
	void desenhar(sf::Drawable& forma);
	void atualizarTela();
	//void carregarTextura(sf::Texture& textura, const std::string& arquivo);
	//void carregarTextura(sf::Texture& textura, sf::IntRect area, const std::string& arquivo);
	void carregarTexturas();
	void carregarTextura(Texturas id, const std::string& arquivo);
	sf::Texture& getTextura(Texturas id);
	void carregarFonte(sf::Font& fonte, const std::string& arquivo);
};
