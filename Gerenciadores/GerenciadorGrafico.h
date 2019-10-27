#pragma once
#include <list>

using namespace std;

class Entidade;

class GerenciadorGrafico
{
	list<Entidade*> elementos;
	list<Entidade*>::iterator iterador;
public:
	void Inserir(Entidade* entidade);
	void Executar();
};

