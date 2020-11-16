#include "Parque.h"
#include <vector>

using namespace std;

//a)
ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli) : lotacao(lot), numMaximoClientes(nMaxCli) {
	this->vagas = lot;
}


unsigned int ParqueEstacionamento::getNumLugares() const {
	return this->lotacao;
}


unsigned int ParqueEstacionamento::getNumMaximoClientes() const {
	return this->numMaximoClientes;
}

//b)
int ParqueEstacionamento::posicaoCliente(const string & nome) const {
	for (size_t i = 0; i < this->clientes.size(); i++) {
		if (this->clientes[i].nome == nome) {
			return i;
		}
	}

	return -1;
}


bool ParqueEstacionamento::adicionaCliente(const string & nome) {
	if (posicaoCliente(nome) == -1 && this->clientes.size() < this->numMaximoClientes) {
		InfoCartao cli;
		cli.nome = nome;
		cli.presente = false;
		this->clientes.push_back(cli);

		return true;
	}
	else {
		return false;
	}
}

//c)
bool ParqueEstacionamento::entrar(const string & nome) {
	int pos = posicaoCliente(nome);

	if (pos == -1 || this->clientes[pos].presente == true || vagas == 0) {
		return false;
	}
	else {
		this->clientes[pos].presente = true;
		this->vagas--;
		return true;
	}
}

//d)
bool ParqueEstacionamento::retiraCliente(const string & nome) {
	int pos = this->posicaoCliente(nome);

	if (pos == -1 || this->clientes[pos].presente == true) {
		return false;
	}
	else {
		vector<InfoCartao>::iterator it;
		for (it = this->clientes.begin(); it != this->clientes.end(); it++) {
			if (it->nome == nome) {
				this->clientes.erase(it);
				break;
			}
		}

		return true;
	}
}

//e)
bool ParqueEstacionamento::sair(const string & nome) {
	int pos = this->posicaoCliente(nome);

	if (pos == -1 || this->clientes[pos].presente == false) {
		return false;
	}
	else {
		this->clientes[pos].presente = false;
		return true;
	}
}

//f)
unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
	return this->lotacao - this->vagas;
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
	return this->clientes.size();
}














