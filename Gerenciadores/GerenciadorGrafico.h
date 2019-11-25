#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../Listas/MapaRecursos.h"

namespace Gerenciadores {
	class GerenciadorGrafico
	{
	private:
		sf::RenderWindow* janela;
		static GerenciadorGrafico* instancia;
		GerenciadorGrafico();
		~GerenciadorGrafico();
	public:
		enum Texturas {
			Plataforma,
			Grama,
			PlataformaGrama,
			PlataformaGramaPequenaBaixa,
			PlataformaGramaPequenaMedia,
			PlataformaGramaPequenaGrande,
			PlataformaGramaMediaBaixa,
			PlataformaTijolo1,
			PlataformaTijolo2,
			PlataformaTijolo3,
			PlataformaTijolo4,
			PlataformaTijolo5,
			Lava,
			Escada,
			Coracao,
			Cavaleiro,
			Mago,
			Anao,
			Aranha,
			Fenix,
			Floresta,
			Caverna,
			Estalactite,
			TeiaDeAranha,
			Fogo,
			BolaDeFogo,
			menuDead,
			menuPause,
			menuGame,
		};
	private:
		Listas::MapaRecursos<GerenciadorGrafico::Texturas, sf::Texture> mapaTexturas;
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
}