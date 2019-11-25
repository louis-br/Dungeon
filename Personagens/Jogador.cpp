#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

Personagens::Jogador::Jogador(sf::Vector2f pos, sf::Vector2f tam, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
    Personagem(pos, tam, lista, vetor),
    direita(sf::Keyboard::Right),
    esquerda(sf::Keyboard::Left),
    cima(sf::Keyboard::Up),
    baixo(sf::Keyboard::Down),
    teclas{direita, esquerda, cima, baixo}
{
    potencialVelocidade = sf::Vector2f(0.f, 260.f);
    potencialAceleracao = sf::Vector2f(260.f, 0.f);
    velocidadeMaxima = sf::Vector2f(130.f, 0.f);
    estado = Estado::Pulando;
}

Personagens::Jogador::~Jogador() {

}

void Personagens::Jogador::setTeclas(sf::Keyboard::Key* novo) {
    for (int i = 0; i < 4; ++i) {
        teclas[i] = novo[i];
    }
    direita = teclas[0];
    esquerda = teclas[1];
    cima = teclas[2];
    baixo = teclas[3];
}

sf::Keyboard::Key* Personagens::Jogador::getTeclas() {
    return teclas;
}

void Personagens::Jogador::atualizarTeclas() {
    mover(sf::Vector2f(
        (float)(sf::Keyboard::isKeyPressed(direita) - sf::Keyboard::isKeyPressed(esquerda)),
        (float)(sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima))
    ));
}

Personagens::Jogador::Tipo Personagens::Jogador::getTipo() {
    if (estado == Estado::Atacando) {
        return Tipo::JogadorAtacando;
    }
    else {
        return Tipo::Jogador;
    }
}

void Personagens::Jogador::colidiuCom(Tipo tipo) {
    if (estado == Estado::Pulando) {
        if (velocidade.y >= -1.f) {
            estado = Estado::Andando;
            atualizar = true;
        }
    }
    if (estado != Estado::Atacando && tipo == Tipo::Hostil && ultimoDano.getElapsedTime().asSeconds() > 5.f) {
        recebeuDano = true;
        --vidas;
        ultimoDano.restart();
    }
}
