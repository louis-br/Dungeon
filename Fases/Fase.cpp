#include "Fase.h"
#include "math.h"

Fases::Fase::Fase(sf::RenderWindow* window, Personagens::Cavaleiro* jog1) :
    fisico(Gerenciadores::GerenciadorFisico::getInstancia()),
    grafico(Gerenciadores::GerenciadorGrafico::getInstancia()),
    janela(window),
    camera(),
    listaEntidade(),
    vetorEntidadeFisica(),
    jogador(jog1),
    jogador2(nullptr)
{
    if (jogador != nullptr) {
        listaEntidade.empilharTras(static_cast<Entidades::Entidade*>(jogador));
        vetorEntidadeFisica.empilharTras(static_cast<Entidades::EntidadeFisica*>(jogador));
    }
}

Fases::Fase::~Fase() {
    listaEntidade.remover(static_cast<Entidades::Entidade*>(jogador));
    vetorEntidadeFisica.remover(static_cast<Entidades::EntidadeFisica*>(jogador));
    if (jogador2 != nullptr) {
        listaEntidade.remover(static_cast<Entidades::Entidade*>(jogador2));
        vetorEntidadeFisica.remover(static_cast<Entidades::EntidadeFisica*>(jogador2));
    }
}

void Fases::Fase::setJogador2(Personagens::Cavaleiro* jog2) {
    if (jog2 == jogador2) {
        return;
    }
    else if (jog2 == nullptr && jogador2 != nullptr) {
        listaEntidade.remover(static_cast<Entidades::Entidade*>(jogador2));
        vetorEntidadeFisica.remover(static_cast<Entidades::EntidadeFisica*>(jogador2));
    }
    jogador2 = jog2;
    if (jogador2 != nullptr) {
        listaEntidade.empilharTras(static_cast<Entidades::Entidade*>(jogador2));
        vetorEntidadeFisica.empilharTras(static_cast<Entidades::EntidadeFisica*>(jogador2));
    }
}

void Fases::Fase::printar(Gerenciadores::GerenciadorGrafico* grafico) {
    grafico->desenhar(sprite);
}

void Fases::Fase::executar(bool pausa) {
    if (pausa) {
        fisico->reiniciarRelogio();
    }
    else {
        fisico->executar(vetorEntidadeFisica, listaEntidade);
    }
    for (int i = 0; i < vetorEntidadeFisica.tamanho();) {
        Entidades::EntidadeFisica* movel = vetorEntidadeFisica[i];
        if (movel->getExcluido()) {
            listaEntidade.remover(movel);
            vetorEntidadeFisica.remover(movel);
        }
        else {
            ++i;
        }
    }
    if (jogador != nullptr) {
        sf::Vector2f centro = jogador->getPosicao() + jogador->getTamanho() * 0.5f;
        camera.setCenter(centro);
        sf::Vector2f tamanho = static_cast<sf::Vector2f>(janela->getSize());
        camera.setSize(tamanho);
        camera.zoom(0.5f);
        centro = centro - tamanho;
        sf::IntRect retanguloTextura = sprite.getTextureRect();
        sf::Vector2f tamanhoFundo = sf::Vector2f(retanguloTextura.width * 0.5f, retanguloTextura.height);
        sprite.setPosition(sf::Vector2f(centro.x - fmodf(centro.x, tamanhoFundo.x)*0.5f, centro.y - fmodf(centro.y, tamanhoFundo.y)*0.5f));
    }
    if (janela != nullptr) {
        janela->setView(camera);
    }
    printar(grafico);
    listaEntidade.printar();
}
