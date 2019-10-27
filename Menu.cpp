#include "Menu.h"

Menu::Menu(GerenciadorGrafico* grafico) :
	Entidade(0, 0, 200, 200, grafico),
	forma(100.f)
{
	CriarGraficos();
}

Menu::~Menu() {

}

void Menu::Executar() {

}

void Menu::CriarGraficos() {
	forma.setFillColor(sf::Color::Green);
}

void Menu::Apresentar(GerenciadorGrafico& grafico)
{
	grafico.Desenhar(forma);
}
