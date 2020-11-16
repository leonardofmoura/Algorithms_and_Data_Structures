
#include "animal.h"

string Animal::getNome() const {
	return nome;
}


int Voador::getAltMAx() const {
	return this->altura_max;
}

int Voador::getVelMax() const {
	return this->velocidade_max;
}

int Animal::getIdade() const {
	return this->idade;
}


//a)
int Animal::maisJovem = 999999;

Animal::Animal(string nome, int idade) {
	this->nome = nome;
	this-> idade = idade;
	this->vet = new Veterinario("",0);

	if (idade < maisJovem) {
		maisJovem = idade;
	}
}


Cao::Cao(string nome, int idade, string raca) : Animal(nome,idade) {
	this->raca = raca;
}

Voador::Voador(int vmax, int amax) {
	this->altura_max = amax;
	this->velocidade_max = vmax;
}

Morcego::Morcego(string nome, int idade, int vmax, int amax) : Animal(nome,idade), Voador(vmax,amax) {

}

int Animal::getMaisJovem() {
	return Animal::maisJovem;
}


bool Cao::eJovem() const {
	return this->idade < 5;
}


bool Morcego::eJovem() const {
	return this->idade < 4;
}


//b)
string Cao::getInformacao() const {
	if (this->vet->getNome() == "") {
		return this->nome + ", " + to_string(this->idade) + ", " + this->raca;
	}
	else {
		return this->nome + ", " + to_string(this->idade) + ", " + this->vet->getNome() + ", " + to_string(this->vet->getCode()) + ", " + this->raca;
	}
}


string Morcego::getInformacao() const {
	if (this->vet->getNome() == "") {
		return this->nome + ", " + to_string(this->idade) + ", " + to_string(this->getVelMax()) + ", " + to_string(this->getAltMAx()) + this->vet->getNome();
	}
	else {
		return this->nome + ", " + to_string(this->idade) + ", " + this->vet->getNome() + ", " + to_string(this->vet->getCode()) + ", " + to_string(this->getVelMax()) + ", " + to_string(this->getAltMAx()) + ", ";
	}
}

//e)
void Animal::setVet(Veterinario* vet) {
	this->vet = vet;
}


//f)
string Animal::getVetName() const  {
	return this->vet->getNome();
}










