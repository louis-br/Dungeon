#include "Inimigo.h"

Personagens::Inimigo::Inimigo(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
    Personagem(pos, tam, lista, vetor)
{
    vidas = 1;
    potencialVelocidade = sf::Vector2f(0.f, 100.f);
    potencialAceleracao = sf::Vector2f(100.f, 0.f);
    velocidadeMaxima = sf::Vector2f(130.f, 100.f);
}

Personagens::Inimigo::~Inimigo() {

}

Personagens::Inimigo::Tipo Personagens::Inimigo::getTipo() {
    return Tipo::Hostil;
}

void Personagens::Inimigo::colidiuCom(Tipo tipo) {
    estado = Estado::Andando;
    if ((int)tipo > 0) {
        sentido = !sentido;
    }
    if (tipo == Tipo::JogadorAtacando && ultimoDano.getElapsedTime().asSeconds() > 1.f) {
        recebeuDano = true;
        --vidas;
        ultimoDano.restart();
        if (vidas == 0) {
            excluido = true;
        }
    }
}
