#include "zoo.h"


int Zoo::numAnimais() const {
	return animais.size();
}

int Zoo::numVeterinarios() const {
	return veterinarios.size();
}

//b)
void Zoo::adicionaAnimal(Animal* a1) {
	this->animais.push_back(a1);
}


//c)
string Zoo::getInformacao() const {
	string temp = "";

	for (size_t i = 0; i < this->animais.size(); i++) {
		temp += this->animais[i]->getInformacao() + "\n";
	}

	return temp;
}

//d)
bool Zoo::animalJovem(string nomeA) {
	for (size_t i = 0; i < this->animais.size(); i++) {
		if (this->animais[i]->eJovem() && this->animais[i]->getNome() == nomeA) {
			return true;
		}
	}

	return false;
}


//e)
void Zoo::alocaVeterinarios(istream & isV) {
	while(!isV.eof()) {
		Veterinario* vet1 = new Veterinario("",0);
		string nome;
		string code;

		getline(isV,nome);
		nome.erase(nome.length() - 1);  //remove \n from the end of the string

		getline(isV,code);


		vet1->setNome(nome);
		vet1->setCod(stoi(code));

		this->veterinarios.push_back(vet1);
	}


	for (size_t i = 0; i < this->animais.size(); i++) {
		this->animais[i]->setVet(this->veterinarios[i % this->veterinarios.size()]);
	}
}


//f)
bool Zoo::removeVeterinario(string nomeV) {
	for (size_t i = 0; i < this->veterinarios.size(); i++) {
		if (this->veterinarios[i]->getNome() == nomeV) {

			for (size_t j = 0; j < this->animais.size(); j++) {
				if (this->animais[j]->getVetName() == nomeV) {
					this->animais[j]->setVet(this->veterinarios[(i+1) % this->veterinarios.size()]);
				}
			}

			return true;

		}
	}

	return false;
}


//g)
bool Zoo::operator <(Zoo & zoo2) const {
	int sum1 = 0;
	int sum2 = 0;

	for (size_t i = 0; i < this->animais.size(); i++) {
		sum1 += this->animais[i]->getIdade();
	}

	for (size_t i = 0; i < zoo2.animais.size(); i++) {
		sum2 += zoo2.animais[i]->getIdade();
	}

	return sum1 < sum2;
}









