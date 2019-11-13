#pragma once
#include <list>
#include <SFML/Graphics.hpp>

using namespace std;

class Entidade;

class GerenciadorGrafico
{
private:
	sf::RenderWindow* janela;
	list<Entidade*> elementos;
	list<Entidade*>::iterator iterador;
public:
	GerenciadorGrafico(sf::RenderWindow* window);
	~GerenciadorGrafico();
	void Inserir(Entidade* entidade);
	void Executar();
	void Desenhar(sf::Drawable& forma);
	void CarregarFonte(sf::Font& fonte, const std::string& arquivo);
};