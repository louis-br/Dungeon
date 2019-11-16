#include "DefesaInvasao.h"

DefesaInvasao::DefesaInvasao(sf::RenderWindow* janela) :
	Fase(janela)
{
	CriarTerreno();
}

DefesaInvasao::~DefesaInvasao() {

}

void DefesaInvasao::CriarTerreno() {
	new Tijolo(sf::Vector2f(0, 134), sf::Vector2f(16 * 9, 16), &listaEntidade);
}