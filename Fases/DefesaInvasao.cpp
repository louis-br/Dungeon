#include "DefesaInvasao.h"

DefesaInvasao::DefesaInvasao(sf::RenderWindow* janela) :
	Fase(janela)
{
	criarTerreno();
}

DefesaInvasao::~DefesaInvasao() {

}

void DefesaInvasao::criarTerreno() {
	//new Fundo(sf::Vector2f(0, 0), sf::Vector2f(11500, 140), &listaEntidade);
	new Tijolo(sf::Vector2f(0, 268), sf::Vector2f(11500, 140), &listaEntidade);
}