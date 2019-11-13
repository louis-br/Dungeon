#pragma once
#include <SFML/Graphics.hpp>

class Fase
{
private:
	sf::View camera;
public:
	Fase();
	virtual ~Fase();
	virtual void CriarTerreno() = 0;
};
