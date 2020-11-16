#include "Veiculo.h"
#include <iostream>

using namespace std;

//a)
Veiculo::Veiculo(string mc, int m, int a) {
	this->marca = mc;
	this->mes = m;
	this->ano = a;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil) : Veiculo::Veiculo(mc,m,a){
	this->combustivel = c;
	this->cilindrada = cil;
}


Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado::Motorizado(mc,m,a,c,cil){ }


Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm) : Motorizado::Motorizado(mc,m,a,c,cil) {
	this->carga_maxima = cm;
}


Bicicleta::Bicicleta(string mc, int m, int a, string t) : Veiculo::Veiculo(mc,m,a) {
	this->tipo = t;
}


string Motorizado::getCombustivel() const {
	return this->combustivel;
}


string Veiculo::getMarca() const {
	return this->marca;
}

int Veiculo::getAno() const {
	return this->ano;
}



//c)
int Veiculo::info() const {
	cout << "Marca:" << this->marca << "\nMes:" << this->mes << "\nAno:" << this->ano << endl;

	return 3;
}


int Motorizado::info() const {
	cout << "Marca:" << this->marca << "\nMes:" << this->mes << "\nAno:" << this->ano << endl;
	cout << "Combustivel:" << this->combustivel << "\nCilindrada:" << this->cilindrada << endl;

	return 5;
}


int Automovel::info() const {

	return Motorizado::info();
}


int Camiao::info() const {
	Motorizado::info();
	cout << "Carga Maxima:" << this->carga_maxima << endl;

	return 6;
}

int Bicicleta::info() const {
	Veiculo::info();

	cout << "Tipo:" << this->tipo << endl;

	return 4;
}


//e)
int Veiculo::getMes() const {
	return this->mes;
}


bool Veiculo::operator <(const Veiculo & v) const {
	if (this->ano == v.getAno())  {
		return this->mes < v.getMes();
	}
	else {
		return this->ano < v.getAno();
	}
}



//g)
float Motorizado::calcImposto() const {

	if (this->combustivel == "gasolina") {
		if (this->cilindrada <= 1000) {
			if (this->ano <= 1995) {return 8.10;}
			else {return 14.56;}
		}
		else if (this->cilindrada <= 1300) {
			if (this->ano <= 1995) {return 14.56;}
			else {return 29.06;}
		}
		else if (this->cilindrada <= 1750) {
			if (this->ano <= 1995) {return 22.65;}
			else {return 45.15;}
		}
		else if (this->cilindrada <= 2600) {
			if (this->ano <= 1995) {return 54.89;}
			else {return 113.98;}
		}
		else if (this->cilindrada <= 3500) {
			if (this->ano <= 1995) {return 87.13;}
			else {return 181.17;}
		}
		else {
			if (this->ano <= 1995) {return 148.37;}
			else {return 320.89;}

		}
	}
	else {
		if (this->cilindrada <= 1500) {
			if (this->ano <= 1995) {return 8.10;}
			else {return 14.56;}
		}
		else if (this->cilindrada <= 2000) {
			if (this->ano <= 1995) {return 14.56;}
			else {return 29.06;}
		}
		else if (this->cilindrada <= 3000) {
			if (this->ano <= 1995) {return 22.65;}
			else {return 45.15;}
		}
		else {
			if (this->ano <= 1995) {return 54.89;}
			else {return 113.98;}
		}
	}

}









































