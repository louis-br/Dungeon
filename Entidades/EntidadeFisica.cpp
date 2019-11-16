#include "EntidadeFisica.h"

EntidadeFisica::EntidadeFisica(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* lista) :
	Entidade(pos, tam, lista),
	velocidade(0, 0),
	aceleracao(0, 0),
	velocidadeMaxima(0, 0)
{

}

EntidadeFisica::~EntidadeFisica() {

}