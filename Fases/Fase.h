#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorFisico.h"
#include "../Gerenciadores/GerenciadorEntrada.h"
//#include "../Listas/ListaEntidade.h"
//#include "../Listas/VetorEntidadeFisica.h"
//#include "../Personagens/CavaleiroAntigo.h"
#include "../Blocos/Fundo.h"
#include "../Personagens/Cavaleiro.h"

class Fase
{
protected:
	GerenciadorFisico* fisico;
	GerenciadorGrafico* grafico;
	sf::RenderWindow* janela;
	sf::View camera;
	ListaEntidade listaEntidade;
	VetorEntidadeFisica vetorEntidadeFisica;
	//CavaleiroAntigo jogador;
	Fundo fundo;
	Cavaleiro jogador;
public:
	Fase(sf::RenderWindow* janela = nullptr);
	virtual ~Fase();
	virtual void criarTerreno() = 0;
	void executar();
};