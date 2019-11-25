#pragma once
#include "../Entidades/Entidade.h"
#include "../Gerenciadores/GerenciadorGrafico.h"

namespace Plataformas {
	class Plataforma : public Entidades::Entidade
	{
	public:
		Plataforma(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), Listas::ListaEntidade* lista = nullptr, Gerenciadores::GerenciadorGrafico::Texturas tex = Gerenciadores::GerenciadorGrafico::Texturas::Plataforma);
		~Plataforma();
		void printar(Gerenciadores::GerenciadorGrafico* grafico);
	};
}