/*
 * Empacotador.cpp
 */

#include "MaquinaEmpacotar.h"


MaquinaEmpacotar::MaquinaEmpacotar(int capCaixas): capacidadeCaixas(capCaixas)
{}

unsigned MaquinaEmpacotar::numCaixasUsadas() {
	return caixas.size();
}

unsigned MaquinaEmpacotar::addCaixa(Caixa& cx) {
	caixas.push(cx);
	return caixas.size();
}

HEAP_OBJS MaquinaEmpacotar::getObjetos() const {
	return this->objetos;
}

HEAP_CAIXAS MaquinaEmpacotar::getCaixas() const {
	return this->caixas;
}


/* a implementar pelos estudantes */

unsigned MaquinaEmpacotar::carregaPaletaObjetos(vector<Objeto> &objs) {
	int i = 0;
	vector<Objeto>::iterator it;

	for ( it = objs.begin(); it != objs.end(); it++) {
		if (it->getPeso() <= this->capacidadeCaixas) {
			this->objetos.push(*it);

			objs.erase(it);
			it--;
			i++;
		}
	}


	return i;
}


Caixa MaquinaEmpacotar::procuraCaixa(Objeto& obj) {
	HEAP_CAIXAS temp;

	while (!this->caixas.empty()) {
		if (this->caixas.top().getCargaLivre() >= obj.getPeso()) {
			Caixa c1 = this->caixas.top();

			this->caixas.pop();

			while(!temp.empty()) {
				this->caixas.push(temp.top());
				temp.pop();
			}

			return c1;
		}
		else {
			temp.push(this->caixas.top());
			this->caixas.pop();
		}
	}


	while(!temp.empty()) {
		this->caixas.push(temp.top());
		temp.pop();
	}



	Caixa cx;

	return cx;
}


unsigned MaquinaEmpacotar::empacotaObjetos() {
	// TODO
	return 0;
}

string MaquinaEmpacotar::imprimeObjetosPorEmpacotar() const {
	// TODO
	return "";
}



Caixa MaquinaEmpacotar::caixaMaisObjetos() const {
	// TODO
	Caixa cx;
	return cx;
}



