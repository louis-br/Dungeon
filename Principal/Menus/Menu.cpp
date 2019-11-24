#include "Menu.h"

Menu::Menu(sf::RenderWindow* window, sf::Vector2f pos, sf::Vector2f tam) :
	Entidade(pos, tam),
	janela(window),
	fundo(tam * 0.8f),
	fonte(),
	titulo(sf::String("Dungeon++"), fonte),
	cima(sf::Keyboard::Up),
	baixo(sf::Keyboard::Down),
	confirma(sf::Keyboard::Enter),
	opcao(0),
	ligado(true),
	confirmado(false)
{
	GerenciadorGrafico* grafico = GerenciadorGrafico::getInstancia();
	if (grafico != nullptr) {
		grafico->carregarFonte(fonte, "Recursos/Fontes/vinque.ttf");
	}
	fundo.setFillColor(sf::Color(255, 255, 255, 128));
	fundo.setPosition(posicao + tamanho * 0.1f);
	titulo.setCharacterSize(96);
	titulo.setFillColor(sf::Color::Black);
	titulo.setOrigin(sf::Vector2f(titulo.getLocalBounds().width * 0.5f, 0.f));
	titulo.setPosition(posicao + sf::Vector2f(tamanho.x * 0.5f, tamanho.y * 0.1f));
}

Menu::~Menu() {

}

void Menu::setLigado(bool lig) {
	ligado = lig;
}

bool Menu::getLigado() {
	return ligado;
}

void Menu::atualizarTeclas() {
	opcao += sf::Keyboard::isKeyPressed(baixo) - sf::Keyboard::isKeyPressed(cima);
	if (sf::Keyboard::isKeyPressed(confirma)) {
		confirmado = true;
	}
}
