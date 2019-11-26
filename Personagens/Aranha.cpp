#include "Aranha.h"

Personagens::Aranha::Aranha(sf::Vector2f pos, Listas::ListaEntidade* lista, Listas::VetorEntidadeFisica* vetor) :
    Inimigo(pos, sf::Vector2f(14, 11), lista, vetor)
{
    setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Aranha);
    //sprite.setTextureRect(sf::IntRect(0, 0, 14, 11));
}

Personagens::Aranha::~Aranha() {

}

void Personagens::Aranha::printar(Gerenciadores::GerenciadorGrafico* grafico) {
    if (posicao.y > 800) {
        posicao = sf::Vector2f(posicao.x, -200);
    }
    printarCoracoes(grafico);
    printarDano(grafico, 1.f);
    sentido = (int)(relogio.getElapsedTime().asSeconds() * 0.25f) % 2 == 0;
    if (!sentido) {
        sentido = -1;
    }
    mover(sf::Vector2f(sentido, -1));
    sprite.setPosition(posicao);
    sprite.setTextureRect(sf::IntRect((sentido < 0) * 14, 0, sentido * 14, 11));
    grafico->desenhar(sprite);
}