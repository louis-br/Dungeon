#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorFisico.h"
#include "../Gerenciadores/GerenciadorEntrada.h"
//#include "../Listas/ListaEntidade.h"
//#include "../Listas/VetorEntidadeFisica.h"
#include "../Personagens/Cavaleiro.h"

class Fase
{
protected:
	GerenciadorFisico* fisico;
	sf::RenderWindow* janela;
	sf::View camera;
	ListaEntidade listaEntidade;
	VetorEntidadeFisica vetorEntidadeFisica;
	Cavaleiro jogador;
public:
	Fase(sf::RenderWindow* janela = nullptr);
	virtual ~Fase();
	virtual void criarTerreno() = 0;
	void executar();
};