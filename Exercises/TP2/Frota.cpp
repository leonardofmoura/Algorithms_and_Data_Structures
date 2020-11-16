#include "Frota.h"
#include <string>

using namespace std;



//b)
void Frota::adicionaVeiculo(Veiculo *v1) {
	this->veiculos.push_back(v1);
}


int Frota::numVeiculos() const {
	return this->veiculos.size();
}


int Frota::menorAno() const {
	if (this->veiculos.size() == 0) {
		return 0;
	}
	else {

		int menor_ano = this->veiculos[0]->getAno();

		for (size_t i = 0; i < this->veiculos.size(); i++) {
			if (this->veiculos[i]->getAno() < menor_ano) {
				menor_ano = this->veiculos[i]->getAno();
			}
		}

		return menor_ano;
	}
}

//f)
vector<Veiculo *> Frota::operator ()(int anoM) const  {
	vector<Veiculo *> temp;

	for (size_t i = 0; i < this->veiculos.size(); i++) {
		if (veiculos[i]->getAno() == anoM) {
			temp.push_back(veiculos[i]);
		}
	}

	return temp;
}


//h)
float Frota::totalImposto() const {
	float total = 0;

	for (size_t i = 0; i < this->veiculos.size(); i++) {
		total += this->veiculos[i]->calcImposto();
	}

	return total;
}

















