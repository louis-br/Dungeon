#include "Anao.h"

Personagens::Anao::Anao(sf::Vector2f pos, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
    Inimigo(pos, sf::Vector2f(36, 65), lista, vetor)
{
    setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Anao);
    sprite.setTextureRect(sf::IntRect(30, 7, 36, 65));
    potencialVelocidade = sf::Vector2f(0.f, 130.f);
    potencialAceleracao = sf::Vector2f(100.f, 0.f);
    velocidadeMaxima = sf::Vector2f(130.f, 0.f);
}

Personagens::Anao::~Anao() {

}

void Personagens::Anao::printar(Gerenciadores::GerenciadorGrafico* grafico) {
    if (posicao.y > 800) {
        posicao = sf::Vector2f(posicao.x, 0);
    }
    printarCoracoes(grafico);
    printarDano(grafico, 1.f);
    sentido = (int)(relogio.getElapsedTime().asSeconds() * 0.25f) % 2 == 0;
    if (!sentido) {
        sentido = -1;
    }
    mover(sf::Vector2f(sentido, 0));
    sprite.setPosition(posicao);
    sprite.setTextureRect(sf::IntRect(30 + (sentido < 0)*36, 7, sentido*36, 65));
    grafico->desenhar(sprite);
}
