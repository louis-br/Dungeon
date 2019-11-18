#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorFisico.h"
//#include "../Listas/ListaEntidade.h"
//#include "../Listas/VetorEntidadeFisica.h"
#include "../Personagens/Guerreiro.h"

class Fase
{
protected:
	GerenciadorFisico* fisico;
	ListaEntidade listaEntidade;
	VetorEntidadeFisica vetorEntidadeFisica;
	sf::View camera;
	Guerreiro jogador;
public:
	Fase(sf::RenderWindow* janela = nullptr);
	virtual ~Fase();
	virtual void criarTerreno() = 0;
	void executar();
};