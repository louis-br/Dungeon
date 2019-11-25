#pragma once
#include "Fase.h"

class Caverna : public Fase
{
public:
    Caverna(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
    ~Caverna();
    void criarTerreno();
};
