#pragma once
#include "../Entidades/Entidade.h"

class TeiaDeAranha : public Entidade
{
private:
	sf::Texture textura;
	sf::Sprite sprite;
public:
	TeiaDeAranha(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Vector2f tam = sf::Vector2f(0, 0), ListaEntidade* lista = nullptr);
	~TeiaDeAranha();
};