
#include "veterinario.h"


string Veterinario::getNome() const {
	return nome;
}

long Veterinario::getCode() const {
	return this->codOrdem;
}


//a)
Veterinario::Veterinario(string nome, int cod) {
	this->codOrdem = cod;
	this->nome = nome;
}



//e)
void Veterinario::setCod(long cod) {
	this->codOrdem = cod;
}

void Veterinario::setNome(string nome) {
	this->nome = nome;
}


