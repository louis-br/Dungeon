#pragma once
#include <map>

template<class ID, class Recurso>
class MapaRecursos
{
private:
	std::map<ID, Recurso*> mapa;
public:
	void carregarRecurso(ID id, std::string arquivo) {

		Recurso* recurso(new Recurso());
		recurso->loadFromFile(arquivo);

		mapa.insert(std::make_pair(id, std::move(recurso)));
	}
	Recurso& getRecurso(ID id) {
		auto it = mapa.find(id);
		return *it->second;
	}

	MapaRecursos() {}
	~MapaRecursos() {
		mapa.clear();
	}
};
