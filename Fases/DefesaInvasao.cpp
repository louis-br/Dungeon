#include "DefesaInvasao.h"

DefesaInvasao::DefesaInvasao(sf::RenderWindow* janela, Cavaleiro* jog1) :
	Fase(janela, jog1)
{
	textura = GerenciadorGrafico::getInstancia()->getTextura(
						  GerenciadorGrafico::Texturas::Floresta);
	textura.setRepeated(true);
	fundo.setTexture(textura);
	fundo.setTextureRect(sf::IntRect(0, 0, 1920*2, 1080));
	criarTerreno();
}

DefesaInvasao::~DefesaInvasao() {

}

void DefesaInvasao::criarTerreno() {
	//new Fundo(sf::Vector2f(0, 0), sf::Vector2f(11500, 140), &listaEntidade);
	new Tijolo(sf::Vector2f(0, 268), sf::Vector2f(11500, 140), &listaEntidade);
}