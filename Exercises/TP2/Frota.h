#ifndef FROTA_H_
#define FROTA_H_

#include <vector>
#include <sstream>
#include "Veiculo.h"

using namespace std;


class Frota {
	vector<Veiculo *> veiculos;
public:
	void adicionaVeiculo(Veiculo *v1);
	int numVeiculos() const;
	int menorAno() const;
	vector<Veiculo *> operator()(int anoM) const;
	float totalImposto() const;

	//d)
	friend ostream & operator<<(ostream & o, const Frota & f) {

		for (size_t i = 0; i < f.veiculos.size(); i++) {
			o << f.veiculos[i]->info();
		}

		return o;
	}
};


#endif /*FROTA_H_*/
