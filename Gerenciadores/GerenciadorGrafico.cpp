#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico() :
	janela(nullptr)
{

}

GerenciadorGrafico::~GerenciadorGrafico() {

}

GerenciadorGrafico* GerenciadorGrafico::getInstancia()
{
	if (instancia == nullptr) {
		instancia = new GerenciadorGrafico();
	}
	return instancia;
}

void GerenciadorGrafico::setJanela(sf::RenderWindow* window) {
	janela = window;
}

void GerenciadorGrafico::Limpar() 
{
	if (janela != nullptr) {
		janela->clear();
	}
}

void GerenciadorGrafico::Desenhar(sf::Drawable& desenho)
{
	if (janela != nullptr) {
		janela->draw(desenho);
	}
}

void GerenciadorGrafico::AtualizarTela() 
{
	if (janela != nullptr) {
		janela->display();
	}
}

void GerenciadorGrafico::CarregarFonte(sf::Font& fonte, const std::string& arquivo)
{
	if (!fonte.loadFromFile(arquivo)) {
		std::cout << "Falha ao carregar fonte: " << arquivo << '\n';
	}
}
