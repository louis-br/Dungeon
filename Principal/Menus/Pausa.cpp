#include "Pausa.h"

Principal::Menus::Pausa::Pausa(sf::RenderWindow* window, sf::Vector2f pos, sf::Vector2f tam) :
	Menu(window, pos, tam),
	fase(false),
	multijogador(false),
	sair(false),
	opcoes{
		sf::Text(sf::String("Continuar"), fonte),
		sf::Text(sf::String("Menu principal"), fonte),
}
{
	titulo.setString("Pausado");
	for (int i = 0; i < 2; ++i) {
		opcoes[i].setCharacterSize(72);
		opcoes[i].setFillColor(sf::Color::Black);
		opcoes[i].setOrigin(sf::Vector2f(opcoes[i].getLocalBounds().width * 0.5f, 0.f));
		opcoes[i].setPosition(posicao + sf::Vector2f(tamanho.x * 0.5f, tamanho.y * 0.5f + 72 * (i - 1)));
	}
}

Principal::Menus::Pausa::~Pausa() {

}

bool Principal::Menus::Pausa::getSair() {
	return sair;
}

int Principal::Menus::Pausa::executar() {
	if (confirmado) {
		ligado = false;
		switch (opcao) {
		case (Opcoes::Continuar):
			break;
		case (Opcoes::Sair):
			sair = true;
			break;
		}
		confirmado = false;
	}
	return !ligado;
}

void Principal::Menus::Pausa::printar(Gerenciadores::GerenciadorGrafico* grafico) {
	janela->setView(janela->getDefaultView());
	grafico->desenhar(fundo);
	grafico->desenhar(titulo);
	opcao = (opcao + 2) % 2;
	for (int i = 0; i < 2; ++i) {
		if (opcao == i) {
			opcoes[i].setFillColor(sf::Color(255, 0, 0));
		}
		else {
			opcoes[i].setFillColor(sf::Color::Black);
		}
		grafico->desenhar(opcoes[i]);
	}
}

void Principal::Menus::Pausa::atualizarTeclas() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		ligado = true;
	}
	if (ligado) {
		ligado = true;
		opcao += sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima);
		if (sf::Keyboard::isKeyPressed(confirma)) {
			confirmado = true;
		}
	}
}