#pragma once

template <class TL>
class Lista
{
private:
	template <class TE>
	class Elemento {
	private:
		Elemento<TE>* pProx;
	public:
		Elemento() {}
		~Elemento() {}
		Elemento<TE*> getProximo() {}
	};
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
public:
	Lista() {}
	~Lista() {}
	Elemento<TL>* getPrimeiro() { return pPrimeiro; }
	Elemento<TL>* getUltimo() { return pUltimo; }
};

