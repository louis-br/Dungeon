#pragma once
#include "Fase.h"
#include "../Personagens/Fenix.h"

class Caverna : public Fase
{
public:
    Caverna(sf::RenderWindow* janela = nullptr, Cavaleiro* jog1 = nullptr);
    ~Caverna();
    void criarTerreno();
};
