#include "GerenciadorGrafico.h"
#include "../Entidade.h"

GerenciadorGrafico::GerenciadorGrafico(sf::RenderWindow* window) :
	janela(window)
{

}

GerenciadorGrafico::~GerenciadorGrafico() {

}

void GerenciadorGrafico::Inserir(Entidade* entidade)
{
	elementos.push_back(entidade);
}

void GerenciadorGrafico::Executar()
{
	janela->clear();
	GerenciadorGrafico& grafico = *this;
	for (iterador = elementos.begin(); iterador != elementos.end(); ++iterador) {
		(*iterador)->Apresentar(grafico);
	}
	janela->display();
}

void GerenciadorGrafico::Desenhar(sf::Drawable& desenho) {
	janela->draw(desenho);
}