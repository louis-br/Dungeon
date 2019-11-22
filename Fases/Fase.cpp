#include "Fase.h"

Fase::Fase(sf::RenderWindow* window, Cavaleiro* jog1) :
	fisico(GerenciadorFisico::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	janela(window),
	camera(),
	listaEntidade(),
	vetorEntidadeFisica(),
	//fundo(sf::Vector2f(0, 0), sf::Vector2f(100000, 5000), &listaEntidade),
	fundo(),
	jogador(jog1)//sf::Vector2f(0, 0), &listaEntidade, &vetorEntidadeFisica)
{
	//camera.setCenter(200.f, 150.f); //trocar para personagem
	if (janela != nullptr) {
		camera.setSize(static_cast<sf::Vector2f>(janela->getSize()));
		camera.zoom(0.5f);
		janela->setView(camera);
	}
	if (jogador != nullptr) {
		listaEntidade.empilharTras(static_cast<Entidade*>(jogador));
		vetorEntidadeFisica.empilharTras(static_cast<EntidadeFisica*>(jogador));
	}
}

Fase::~Fase() {

}

void Fase::executar() {
	//std::cout << jogador.getVelocidade().x << ':' << jogador.getVelocidade().y << '\n';
	if (jogador != nullptr) {
		sf::Vector2f centro = jogador->getPosicao() + jogador->getTamanho() * 0.5f;
		camera.setCenter(centro);
		sf::Vector2f tamanho = camera.getSize();
		centro = centro - tamanho;
		sf::IntRect retanguloTextura = fundo.getTextureRect();
		sf::Vector2f tamanhoFundo = sf::Vector2f(retanguloTextura.width, retanguloTextura.height);
		fundo.setPosition(sf::Vector2f(centro.x - fmodf(centro.x, tamanhoFundo.x)*0.5f, centro.y - fmodf(centro.y, tamanhoFundo.y)*0.5f));
	}
	janela->setView(camera);
	grafico->limpar();
	grafico->desenhar(fundo);
	listaEntidade.printar();
	grafico->atualizarTela();
	fisico->executar(vetorEntidadeFisica, listaEntidade);
}
