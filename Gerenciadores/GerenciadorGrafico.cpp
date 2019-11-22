#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico() :
	janela(nullptr)
{
	carregarTexturas();
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

void GerenciadorGrafico::limpar() 
{
	if (janela != nullptr) {
		janela->clear();
	}
}

void GerenciadorGrafico::desenhar(sf::Drawable& desenho)
{
	if (janela != nullptr) {
		janela->draw(desenho);
	}
}

void GerenciadorGrafico::atualizarTela() 
{
	if (janela != nullptr) {
		janela->display();
	}
}

void GerenciadorGrafico::carregarTexturas() {
	carregarTextura(Texturas::Tijolo, "Recursos/Plataformas/Plataforma1.png");
	carregarTextura(Texturas::Grama, "Recursos/Plataformas/Grass.png");
	carregarTextura(Texturas::PlataformaGrama, "Recursos/Plataformas/Plataforma3.png");
	carregarTextura(Texturas::PlataformaGramaPequenaBaixa, "Recursos/Plataformas/PlataformaPequenaBaixa.png");
	carregarTextura(Texturas::PlataformaGramaPequenaMedia, "Recursos/Plataformas/PlataformaPequenaMedia.png");
	carregarTextura(Texturas::PlataformaGramaPequenaGrande, "Recursos/Plataformas/PlataformaPequenaGrande.png");
	carregarTextura(Texturas::PlataformaGramaMediaBaixa, "Recursos/Plataformas/PlataformaMediaBaixa.png");
	carregarTextura(Texturas::Cavaleiro, "Recursos/Personagens/Cavaleiro.png");//"Recursos/Personagens/Original/Anaos.png");
	carregarTextura(Texturas::Orc, "Recursos/Personagens/Inimigo1.png");
	carregarTextura(Texturas::Aranha, "Recursos/Personagens/spider.png");
	carregarTextura(Texturas::Floresta, "Recursos/Fundos/Forest.png");
	carregarTextura(Texturas::Estalactite, "Recursos/Obstaculos/stalactite4.png");
	carregarTextura(Texturas::TeiaDeAranha, "Recursos/Obstaculos/SpiderWeb.png");
}

void GerenciadorGrafico::carregarTextura(Texturas id, const std::string& arquivo)
{
	mapaTexturas.carregarRecurso(id, arquivo);
}

sf::Texture& GerenciadorGrafico::getTextura(Texturas id) {
	return mapaTexturas.getRecurso(id);
}

void GerenciadorGrafico::carregarFonte(sf::Font& fonte, const std::string& arquivo)
{
	if (!fonte.loadFromFile(arquivo)) {
		std::cout << "Falha ao carregar fonte: " << arquivo << '\n';
	}
}

GerenciadorGrafico* GerenciadorGrafico::instancia(nullptr);