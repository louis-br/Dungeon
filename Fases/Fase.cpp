#include "Fase.h"
#include "math.h"

Fase::Fase(sf::RenderWindow* window, Cavaleiro* jog1) :
	fisico(GerenciadorFisico::getInstancia()),
	grafico(GerenciadorGrafico::getInstancia()),
	janela(window),
	camera(),
	listaEntidade(),
	vetorEntidadeFisica(),
	jogador(jog1),
	jogador2(nullptr)
{
	if (jogador != nullptr) {
		listaEntidade.empilharTras(static_cast<Entidade*>(jogador));
		vetorEntidadeFisica.empilharTras(static_cast<EntidadeFisica*>(jogador));
	}
}

Fase::~Fase() {
	listaEntidade.remover(static_cast<Entidade*>(jogador));
	vetorEntidadeFisica.remover(static_cast<EntidadeFisica*>(jogador));
	if (jogador2 != nullptr) {
		listaEntidade.remover(static_cast<Entidade*>(jogador2));
		vetorEntidadeFisica.remover(static_cast<EntidadeFisica*>(jogador2));
	}
}

void Fase::setJogador2(Cavaleiro* jog2) {
	jogador2 = jog2;
	if (jogador2 != nullptr) {
		listaEntidade.empilharTras(static_cast<Entidade*>(jogador2));
		vetorEntidadeFisica.empilharTras(static_cast<EntidadeFisica*>(jogador2));
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
	for (int i = 0; i < vetorEntidadeFisica.tamanho();) {
		EntidadeFisica* movel = vetorEntidadeFisica[i];
		if (movel->getExcluido()) {
			listaEntidade.remover(movel);
			vetorEntidadeFisica.remover(movel);
		}
		else {
			++i;
		}
	}
	if (jogador != nullptr) {
		sf::Vector2f centro = jogador->getPosicao() + jogador->getTamanho() * 0.5f;
		camera.setCenter(centro);
		sf::Vector2f tamanho = static_cast<sf::Vector2f>(janela->getSize());
		camera.setSize(tamanho);
		camera.zoom(0.5f);
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
