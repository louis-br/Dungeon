#include"Caverna.h"

Fases::Caverna::Caverna(sf::RenderWindow* janela, Personagens::Cavaleiro* jog1):
    Fase(janela, jog1)
{
    setTextura(Gerenciadores::GerenciadorGrafico::Texturas::Caverna);
    textura.setRepeated(true);
	sf::Vector2u tam = textura.getSize();
	sprite.setTextureRect(sf::IntRect(0, 0, (int)(textura.getSize().x) * 3, (int)(textura.getSize().y) * 3));
    //sprite.setTextureRect(sf::IntRect(0, 0, 1920*2, 1080));
    criarTerreno();
}

Fases::Caverna::~Caverna(){

}

void Fases::Caverna::criarTerreno(){
    //Falta colocar os obstaculos
    std::srand((unsigned int)time(NULL));
    int num = 15 + rand() % 20;
    int num2;

    for(int i = 0; i < num; i++){
        num2 = rand() % 10000;
        new Personagens::Anao(sf::Vector2f((float)num2, -200), &listaEntidade, &vetorEntidadeFisica);
    }
    num = 15 + rand() % 50;

    for(int i = 0; i < num; i++){
        num2 = rand() % 10000;
        new Personagens::Aranha(sf::Vector2f((float)num2, -200), &listaEntidade, &vetorEntidadeFisica);
    }

	num = rand() % 5;

	for (int i = 0; i < num; i++) {
		num2 = 3000 + rand() % 300;
		new Obstaculos::TeiaDeAranha(sf::Vector2f((float)num2, 40), sf::Vector2f(50, 10), &listaEntidade);
	}

	num = 5 + rand() % 5;

	for (int i = 0; i < num; i++) {
		num2 = 10000 + rand() % 200;
		new Obstaculos::Estalactite(sf::Vector2f((float)num2, -258), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	}

    new Plataformas::Plataforma(sf::Vector2f(-500, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(-400, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(-300, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(-200, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(-100, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(0, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(100, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(200, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
	new Plataformas::Plataforma(sf::Vector2f(400, 0), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(400, 0), sf::Vector2f(122, 20), &listaEntidade);
    new Plataformas::Plataforma(sf::Vector2f(700, -50), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(700, -50), sf::Vector2f(122, 20), &listaEntidade);
	new Plataformas::Plataforma(sf::Vector2f(1000, -80), sf::Vector2f(180, 250), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(1100, -130), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(1200, -180), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(1500, -140), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(1500, -140), sf::Vector2f(42, 20), &listaEntidade);
	new Plataformas::Plataforma(sf::Vector2f(1800, -100), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(1800, -100), sf::Vector2f(42, 20), &listaEntidade);
	new Plataformas::Plataforma(sf::Vector2f(2100, -60), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(2100, -60), sf::Vector2f(42, 20), &listaEntidade);
	new Plataformas::Plataforma(sf::Vector2f(2400, -20), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
	new Obstaculos::TeiaDeAranha(sf::Vector2f(2400, -20), sf::Vector2f(42, 20), &listaEntidade);
	new Plataformas::Plataforma(sf::Vector2f(2700, 20), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
    new Plataformas::Plataforma(sf::Vector2f(3000, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(3150, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(3300, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
	new Obstaculos::Estalactite(sf::Vector2f(3300, -218), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(3700, 0), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
	new Obstaculos::Estalactite(sf::Vector2f(3700, -258), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(4000, 0), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
	new Obstaculos::Estalactite(sf::Vector2f(4000, -258), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(4300, 0), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
	new Obstaculos::Estalactite(sf::Vector2f(4300, -258), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(4600, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(4700, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(4800, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(4900, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(5000, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
	new Obstaculos::Estalactite(sf::Vector2f(5000, -218), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(5300, 0), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
	new Obstaculos::Estalactite(sf::Vector2f(5300, -218), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(5550, -40), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
	new Obstaculos::Estalactite(sf::Vector2f(5550, -218), sf::Vector2f(23, 258), &listaEntidade, &vetorEntidadeFisica);
	new Plataformas::Plataforma(sf::Vector2f(5750, -80), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
    new Plataformas::Plataforma(sf::Vector2f(6000, -120), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
    new Plataformas::Plataforma(sf::Vector2f(6300, -160), sf::Vector2f(64, 40), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo2);
    new Plataformas::Plataforma(sf::Vector2f(6600, -160), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(6700, -160), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(7100, -160), sf::Vector2f(42, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo3);
    new Plataformas::Plataforma(sf::Vector2f(7400, -160), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(7500, -160), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(7800, -120), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
    new Plataformas::Plataforma(sf::Vector2f(8100, -80), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
    new Plataformas::Plataforma(sf::Vector2f(8400, -40), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
    new Plataformas::Plataforma(sf::Vector2f(8700, 0), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
    new Plataformas::Plataforma(sf::Vector2f(9000, 0), sf::Vector2f(122, 37), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo4);
    new Plataformas::Plataforma(sf::Vector2f(9300, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9400, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9500, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9600, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9700, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9800, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(9900, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10000, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10100, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10200, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10300, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10400, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10500, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10600, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10700, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10800, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(10900, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(11000, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(11100, 40), sf::Vector2f(180, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
    new Plataformas::Plataforma(sf::Vector2f(11200, 40), sf::Vector2f(11000, 307), &listaEntidade, Gerenciadores::GerenciadorGrafico::PlataformaTijolo5);
}
