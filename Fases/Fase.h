#pragma once
#include <SFML/Graphics.hpp>
#include "../Gerenciadores/GerenciadorFisico.h"
#include "../Gerenciadores/GerenciadorEntrada.h"
//#include "../Listas/ListaEntidade.h"
//#include "../Listas/VetorEntidadeFisica.h"
//#include "../Personagens/Cavaleiro.h"
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
	//Cavaleiro jogador;
	sf::Sprite fundo;
	Cavaleiro* jogador;
public:
	Fase(sf::RenderWindow* window = nullptr, Cavaleiro* jog1 = nullptr);
	void setJogador2(Cavaleiro* jog2);
	virtual ~Fase();
	virtual void criarTerreno() = 0;
	void executar(bool pausa = false);
};