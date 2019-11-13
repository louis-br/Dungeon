#pragma once

template <class TL>
class Lista
{
private:
	template <class TE>
	class Elemento {
	private:
		Elemento<TE>* pProx;
		Elemento<TE>* pElem;
	public:
		Elemento(TE* elemento) :
			pProx(nullptr),
			pElem(elemento) {}
		~Elemento() {}
		Elemento<TE*> getProximo() { return pProx; }
		Elemento<TE*> getElemento() { return pElem; }
		void setProximo(Elemento<TE>* elemento) { pProx = elemento; }
	};
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
public:
	Lista() :
		pPrimeiro(nullptr),
		pUltimo(nullptr) {}
	~Lista() {}
	Elemento<TL>* getPrimeiro() { return pPrimeiro; }
	Elemento<TL>* getUltimo() { return pUltimo; }
	void Inserir(TL* elemento) {
		Elemento<TL>* novo = new Elemento<TL>(elemento);
		if (pPrimeiro == nullptr) {
			pPrimeiro = novo;
			pUltimo = novo;
		}
		else {
			pUltimo->setProximo(novo);
			pUltimo = novo;
		}
	}
};

