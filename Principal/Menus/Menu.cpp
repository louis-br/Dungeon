#include "Menu.h"
/*
Menu::Menu(sf::Vector2f pos, sf::Vector2f tam, ListaEntidade* grafico) :
	Entidade(pos, tam, grafico),
	fundo(tam * 0.8f),
	fonte(),
	titulo(sf::String("Titulo"), fonte)
{
	criarGraficos(grafico);
}

Menu::~Menu() {

}

void Menu::executar() {

}

void Menu::criarGraficos(ListaEntidade* grafico) {
	if (grafico != nullptr) {
		grafico->carregarFonte(fonte, "Recursos/Fontes/vinque.ttf");
	}
	fundo.setPosition(tamanho * 0.1f);
	titulo.setCharacterSize(96);
	titulo.setFillColor(sf::Color::Black);
	{
		sf::FloatRect extremidades = titulo.getLocalBounds();
		sf::Vector2f tamanhoTexto(extremidades.width, extremidades.height);
		titulo.setPosition(posicao + sf::Vector2f(tamanho.x * 0.5f, tamanho.y * 0.2f) - tamanhoTexto * 0.5f);
	}
}

void Menu::apresentar(ListaEntidade& grafico)
{
	grafico.desenhar(fundo);
	grafico.desenhar(titulo);
}
*/