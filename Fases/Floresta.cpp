#include "Floresta.h"

Fases::Floresta::Floresta(sf::RenderWindow* janela, Personagens::Cavaleiro* jog1) :
	Fase(janela, jog1)
{
	setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Floresta);
	textura.setRepeated(true);
	sf::Vector2u tam = textura.getSize();
	sprite.setTextureRect(sf::IntRect(0, 0, (int)(textura.getSize().x) * 2, (int)(textura.getSize().y) * 3));
	criarTerreno();
}

Fases::Floresta::~Floresta() {

}

void Fases::Floresta::criarTerreno() {
    std::srand(time(NULL));
    int num = 5 + rand() % 20;
    int num2;
    for(int i = 0; i < num; i++){
        num2 = 200 + rand() % 5450;
        new Personagens::Anao(sf::Vector2f(num2, 0), &listaEntidade, &vetorEntidadeFisica);
    }
    num = 5 + rand() % 20;

    for(int i = 0; i < num; i++){
        num2 = 200 + rand() % 5450;
        new Personagens::Aranha(sf::Vector2f(num2, 0), &listaEntidade, &vetorEntidadeFisica);
    }

    num = 5 + rand() % 5;

    for (int i = 0; i < num; i++) {
        num2 = 1000 + rand() % 8000;
        new Obstaculos::TeiaDeAranha(sf::Vector2f(num2, 40), sf::Vector2f(50, 10), &listaEntidade);
    }

    num = 5 + rand() % 5;

    for (int i = 0; i < num; i++) {
        num2 = 1000 + rand() % 8000;
        new Obstaculos::Fogo(sf::Vector2f(num2, 320), sf::Vector2f(8, 15), &listaEntidade);
    }

    new Plataformas::Plataforma(sf::Vector2f(0, 400), sf::Vector2f(200, 200), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Plataformas::Plataforma(sf::Vector2f(200,360), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(230, 350), sf::Vector2f(50, 10), &listaEntidade);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(280, 350), sf::Vector2f(50, 10), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(400,290), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Plataformas::Plataforma(sf::Vector2f(1000, 360), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(1100, 350), sf::Vector2f(50, 10), &listaEntidade);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(1150, 350), sf::Vector2f(50, 10), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(1400,290), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Plataformas::Plataforma(sf::Vector2f(1600, 220), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(1650, 30), sf::Vector2f(50, 10), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(2200, 190), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(2500, 160), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(2800, 130), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Obstaculos::Fogo(sf::Vector2f(2900, 115), sf::Vector2f(8, 15), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(3100, 100), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(3400, 260), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Obstaculos::Fogo(sf::Vector2f(3500, 245), sf::Vector2f(8, 15), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(3700, 320), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Plataformas::Plataforma(sf::Vector2f(4000, 380), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Plataformas::Plataforma(sf::Vector2f(4500, 330), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(4800, 330), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(5100, 330), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Obstaculos::Fogo(sf::Vector2f(5200, 315), sf::Vector2f(8, 15), &listaEntidade);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(5300, 320), sf::Vector2f(50, 10), &listaEntidade);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(5350, 320), sf::Vector2f(50, 10), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(5400, 330), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(7800, 300), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(7850, 290), sf::Vector2f(50, 10), &listaEntidade);
    new Obstaculos::TeiaDeAranha(sf::Vector2f(7850, 290), sf::Vector2f(50, 10), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(5700, 400), sf::Vector2f(600, 200), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Plataformas::Plataforma(sf::Vector2f(6200, 500), sf::Vector2f(600, 200), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Obstaculos::Fogo(sf::Vector2f(6500, 585), sf::Vector2f(8, 15), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(6700, 600), sf::Vector2f(600, 200), &listaEntidade, Gerenciadores::GerenciadorGrafico::Plataforma);
    new Plataformas::Plataforma(sf::Vector2f(7200, 500), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Obstaculos::Fogo(sf::Vector2f(7400, 485), sf::Vector2f(8, 15), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(7500, 400), sf::Vector2f(400, 700), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGramaMediaBaixa);
    new Plataformas::Plataforma(sf::Vector2f(8400, 240), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(8700, 200), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(9000, 160), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
    new Plataformas::Plataforma(sf::Vector2f(9300, 120), sf::Vector2f(148, 75), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaGrama);
}
