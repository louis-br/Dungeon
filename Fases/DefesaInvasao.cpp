#include "DefesaInvasao.h"

DefesaInvasao::DefesaInvasao(sf::RenderWindow* janela) :
	Fase(janela)
{
	criarTerreno();
}

DefesaInvasao::~DefesaInvasao() {

}

void DefesaInvasao::criarTerreno() {
	new Tijolo(sf::Vector2f(0, 268), sf::Vector2f(32 * 9, 32), &listaEntidade);
}