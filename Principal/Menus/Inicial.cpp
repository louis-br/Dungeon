#include "Inicial.h"

Inicial::Inicial(sf::RenderWindow* window, sf::Vector2f pos, sf::Vector2f tam) :
	Menu(window, pos, tam),
	opcoes{
		sf::Text(sf::String("Fase 1"), fonte),
		sf::Text(sf::String("Fase 2"), fonte),
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
	/*iniciar.setCharacterSize(48);
	iniciar.setFillColor(sf::Color::Black);
	iniciar.setOrigin(sf::Vector2f(titulo.getLocalBounds().width * 0.5f, 0.f));
	iniciar.setPosition(posicao + sf::Vector2f(tamanho.x * 0.5f, tamanho.y * 0.1f)); //   - tamanhoTexto * 0.5f*/
}

Inicial::~Inicial() {

}

int Inicial::executar() {
	if (confirmado) {
		confirmado = false;
	}
	else {
		return Opcoes::NaoConfirmado;
	}
	return opcao;
}

void Inicial::setMultijogador(bool multijogador) {
	if (multijogador) {
		opcoes[2].setString(sf::String("Jogadores: 2"));
	}
	else {
		opcoes[2].setString(sf::String("Jogadores: 1"));
	}
}

void Inicial::printar(GerenciadorGrafico* grafico) {
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
