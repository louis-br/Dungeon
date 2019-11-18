#pragma once

template <class TL>
class Lista
{
public:
	template <class TE>
	class Elemento {
	private:
		Elemento<TE>* pProx;
		Elemento<TE>* pAnt;
		TE* pElem;
	public:
		Elemento(TE* elemento) :
			pProx(nullptr),
			pElem(elemento) {}
		~Elemento() {}

		void setProximo(Elemento<TE>* elem) { pProx = elem; }
		Elemento<TE>* getProximo() { return pProx; }
		void setAnterior(Elemento<TE>* elem) { pAnt = elem; }
		Elemento<TE>* getAnterior() { return pAnt; }
		void setElemento(TE* elem) { pElem = elem; }
		TE* getElemento() { return pElem; }
	};
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
public:
	Lista() :
		pPrimeiro(nullptr),
		pUltimo(nullptr) {}
	~Lista() {
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

	Elemento<TL>* getPrimeiro() { return pPrimeiro; }
	Elemento<TL>* getUltimo() { return pUltimo; }

	void empilharTras(TL* elemento) {
		Elemento<TL>* novo = new Elemento<TL>(elemento);
		novo->setElemento(elemento);
		if (pPrimeiro == nullptr) {
			pPrimeiro = novo;
			pUltimo = novo;
		}
		else {
			pUltimo->setProximo(novo);
			pUltimo = novo;
		}
	}

	void desempilharTras() {
		if (pUltimo != nullptr) {
			Elemento<TL>* antigo = pUltimo;
			pUltimo = pUltimo->getAnterior();
			pUltimo.setProximo(nullptr);
			delete antigo;
		}
	}

	void remover(TL* elemento) {
		if (elemento == nullptr) {
			return;
		}
		Elemento<TL>* atual = pPrimeiro;
		while (atual != nullptr) {
			if (*(atual->getElemento) == *elemento) {
				atual->getAnterior()->setProximo(atual->getProximo());
				break;
			}
			atual = atual->getProximo();
		}
	}
};