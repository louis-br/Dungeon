#include "Fase.h"
#include "math.h"

Fase::Fase(sf::RenderWindow* window, Cavaleiro* jog1) :
	fisico(GerenciadorFisico::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	janela(window),
	camera(),
	listaEntidade(),
	vetorEntidadeFisica(),
	jogador(jog1)
{
	//camera.setCenter(200.f, 150.f); //trocar para personagem
	if (janela != nullptr) {
		camera.setSize(static_cast<sf::Vector2f>(janela->getSize()));
		camera.zoom(0.5f);
	}
	if (jogador != nullptr) {
		listaEntidade.empilharTras(static_cast<Entidade*>(jogador));
		vetorEntidadeFisica.empilharTras(static_cast<EntidadeFisica*>(jogador));
	}
}

Fase::~Fase() {

}

void Fase::setJogador2(Cavaleiro* jog2) {
	if (jog2 != nullptr) {
		listaEntidade.empilharTras(static_cast<Entidade*>(jog2));
		vetorEntidadeFisica.empilharTras(static_cast<EntidadeFisica*>(jog2));
	}
}

void Fase::printar(GerenciadorGrafico* grafico) {
	grafico->desenhar(sprite);
}

void Fase::executar(bool pausa) {
	if (pausa) {
		fisico->reiniciarRelogio();
	}
	else {
		fisico->executar(vetorEntidadeFisica, listaEntidade);
	}
	if (jogador != nullptr) {
		sf::Vector2f centro = jogador->getPosicao() + jogador->getTamanho() * 0.5f;
		camera.setCenter(centro);
		sf::Vector2f tamanho = camera.getSize();
		centro = centro - tamanho;
		sf::IntRect retanguloTextura = sprite.getTextureRect();
		sf::Vector2f tamanhoFundo = sf::Vector2f(retanguloTextura.width, retanguloTextura.height);
		sprite.setPosition(sf::Vector2f(centro.x - fmodf(centro.x, tamanhoFundo.x)*0.5f, centro.y - fmodf(centro.y, tamanhoFundo.y)*0.5f));
	}
	if (janela != nullptr) {
		janela->setView(camera);
	}
	printar(grafico);
	listaEntidade.printar();
}
