#include "Inicial.h"

Principal::Menus::Inicial::Inicial(sf::RenderWindow* window, sf::Vector2f pos, sf::Vector2f tam) :
    Menu(window, pos, tam),
    fase(false),
    multijogador(false),
    sair(false),
    opcoes{
        sf::Text(sf::String("Floresta"), fonte),
        sf::Text(sf::String("Caverna"), fonte),
        sf::Text(sf::String("Jogadores: 1"), fonte),
        sf::Text(sf::String("Sair"), fonte),
    }
{
    for (int i = 0; i < 4; ++i) {
        opcoes[i].setCharacterSize(72);
        opcoes[i].setFillColor(sf::Color::Black);
        opcoes[i].setOrigin(sf::Vector2f(opcoes[i].getLocalBounds().width * 0.5f, 0.f));
        opcoes[i].setPosition(posicao + sf::Vector2f(tamanho.x * 0.5f, tamanho.y * 0.5f + 72 * (i - 1)));
    }
}

Principal::Menus::Inicial::~Inicial() {

}

bool Principal::Menus::Inicial::getFase() {
    return fase;
}

bool Principal::Menus::Inicial::getMultijogador() {
    return multijogador;
}

bool Principal::Menus::Inicial::getSair() {
    return sair;
}

int Principal::Menus::Inicial::executar() {
    if (confirmado) {
        ligado = false;
        switch (opcao) {
        case (Opcoes::Fase1):
            fase = false;
            break;
        case (Opcoes::Fase2):
            fase = true;
            break;
        case (Opcoes::Jogadores):
            multijogador = !multijogador;
            if (multijogador) {
                opcoes[2].setString(sf::String("Jogadores: 2"));
            }
            else {
                opcoes[2].setString(sf::String("Jogadores: 1"));
            }
            ligado = true;
            break;
        case (Opcoes::Sair):
            sair = true;
            break;
        }
        confirmado = false;
    }
    return !ligado;
}

void Principal::Menus::Inicial::printar(Gerenciadores::GerenciadorGrafico* grafico) {
    janela->setView(janela->getDefaultView());
    grafico->desenhar(fundo);
    grafico->desenhar(titulo);
    opcao = (opcao + 4) % 4;
    for (int i = 0; i < 4; ++i) {
        if (opcao == i) {
            opcoes[i].setFillColor(sf::Color(255, 0, 0));
        }
        else {
            opcoes[i].setFillColor(sf::Color::Black);
        }
        grafico->desenhar(opcoes[i]);
    }
}
