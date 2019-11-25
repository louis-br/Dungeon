#include "Caverna.h"

Caverna::Caverna(sf::RenderWindow* janela, Cavaleiro* jog1) :
	Fase(janela, jog1)
{
	setTextura(GerenciadorGrafico::Texturas::Caverna);
	textura.setRepeated(true);
	sprite.setTextureRect(sf::IntRect(0, 0, 1920 * 2, 1080));
	criarTerreno();
}

Caverna::~Caverna() {

}

void Caverna::criarTerreno() {
	std::srand(time(NULL));
	int num = 5 + rand() % 20;
	int num2;
	for (int i = 0; i < num; i++) {
		num2 = 200 + rand() % 5450;
		new Anao(sf::Vector2f(num2, 0), &listaEntidade, &vetorEntidadeFisica);
	}
	num = 5 + rand() % 20;

	for (int i = 0; i < num; i++) {
		num2 = 200 + rand() % 5450;
		new Aranha(sf::Vector2f(num2, 0), &listaEntidade, &vetorEntidadeFisica);
	}

	num = 5 + rand() % 20;

	for (int i = 0; i < num; i++) {
		num2 = 200 + rand() % 5450;
		new Estalactite(sf::Vector2f(num2, 0), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	}

	new Plataforma(sf::Vector2f(0, 400), sf::Vector2f(200, 200), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(200, 360), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(400, 290), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(1000, 360), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(1400, 290), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(1600, 220), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(2200, 190), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3); //PlataformaGrama
	new Plataforma(sf::Vector2f(2500, 160), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(2800, 130), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(3100, 100), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(3400, 260), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(3700, 320), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(4000, 380), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(4500, 330), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(4800, 330), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(5100, 330), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(5400, 330), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(5700, 400), sf::Vector2f(600, 200), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(6200, 500), sf::Vector2f(600, 200), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(6700, 600), sf::Vector2f(600, 200), &listaEntidade, GerenciadorGrafico::Plataforma);
	new Plataforma(sf::Vector2f(7200, 500), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(7500, 400), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(7800, 300), sf::Vector2f(400, 700), &listaEntidade, GerenciadorGrafico::PlataformaGramaMediaBaixa);
	new Plataforma(sf::Vector2f(8400, 240), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(8700, 200), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(9000, 160), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	new Plataforma(sf::Vector2f(9300, 120), sf::Vector2f(148, 75), &listaEntidade, GerenciadorGrafico::PlataformaTijolo3);
	//new TeiaDeAranha(sf::Vector2f(0, 268), sf::Vector2f(100, 50), &listaEntidade);
	//new Estalactite(sf::Vector2f(300, 0), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	//new Fogo(sf::Vector2f(400, 268), sf::Vector2f(8, 15), &listaEntidade);
	//new Anao(sf::Vector2f(500, 0), &listaEntidade, &vetorEntidadeFisica);
	//new Aranha(sf::Vector2f(500, 0), &listaEntidade, &vetorEntidadeFisica);
}
