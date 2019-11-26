#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorFisico.h"
#include "../Gerenciadores/GerenciadorEntrada.h"
#include "../Personagens/Cavaleiro.h"
#include "../Listas/ListaEntidade.h"
#include "../Plataformas/Plataforma.h"
#include "../Obstaculos/TeiaDeAranha.h"
#include "../Obstaculos/Estalactite.h"
#include "../Obstaculos/Fogo.h"
#include "../Personagens/Anao.h"
#include "../Personagens/Aranha.h"

namespace Fases {
	class Fase : public Entidades::Entidade
	{
	protected:
		Gerenciadores::GerenciadorFisico* fisico;
		Gerenciadores::GerenciadorGrafico* grafico;
		sf::RenderWindow* janela;
		sf::View camera;
		Personagens::Cavaleiro* jogador;
		Personagens::Cavaleiro* jogador2;
	public:
        Listas::ListaEntidade listaEntidade;
        Listas::VetorEntidadeFisica vetorEntidadeFisica;

		Fase(sf::RenderWindow* window = nullptr, Personagens::Cavaleiro* jog1 = nullptr);
		void setJogador2(Personagens::Cavaleiro* jog2);
		virtual ~Fase();
		virtual void criarTerreno() = 0;
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
		void executar(bool pausa = false);
	};
}
