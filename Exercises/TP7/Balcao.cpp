#include <queue>
#include <cstdlib>
#include "Balcao.h"
#include "exceptions.h"

using namespace std;


Cliente::Cliente() {
	srand(time(NULL));
	int num = rand() % 5 + 1;

	this->numPresentes = num;
}


int Cliente::getNumPresentes() const {

	return this->numPresentes;
}


Balcao::Balcao(int te): tempo_embrulho(te) {
	srand(time(NULL));
	this->tempo_atual = 0;
	this->clientes_atendidos = 0;

	this->prox_chegada = rand() % 20 + 1;
	this->prox_saida = 0;

}      


void Balcao:: proximoEvento()
{
	// a alterar
}


void Balcao::chegada()
{
	Cliente *c = new Cliente();
	this->clientes.push(*c);
	srand(time(NULL));

	this->prox_chegada = rand() % 20 + 1;

	if (clientes.size() == 1) {
		this->prox_saida = this->tempo_atual + c->getNumPresentes() * this->tempo_embrulho;
	}

	cout << "PUTA\n";
}   


void Balcao::saida()
{
	// a alterar
}


int Balcao::getTempoAtual() const { return tempo_atual; }


int Balcao::getProxChegada() const { return prox_chegada; }


ostream & operator << (ostream & out, const Balcao & b1)
{
	// a alterar
     return out;
}


int Balcao::getTempoEmbrulho() const {

	return this->tempo_embrulho;
}


int Balcao::getProxSaida() const {

	return this->prox_saida;
}


int Balcao::getClientesAtendidos() const {

	return this->clientes_atendidos;
}


Cliente & Balcao::getProxCliente() {
	if (clientes.empty()) {

		throw FilaVazia();
	}

	return clientes.front();
}

      
