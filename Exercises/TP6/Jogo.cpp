/*
 * Jogo.cpp
 *
 */

#include "Jogo.h"
using namespace std;
#include <iostream>


int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;
  int n=1;
  int pos = frase.find(' ');
  while ( pos != -1 ) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}


Jogo::Jogo()
{

}

Jogo::Jogo(list<Crianca>& lc2)
{
	this->criancas = lc2;
}

void Jogo::insereCrianca(const Crianca &c1)
{
	this->criancas.push_back(c1);
}

list<Crianca> Jogo::getCriancasJogo() const
{
	return this->criancas;
}


string Jogo::escreve() const
{
	list<Crianca>::const_iterator it = this->criancas.begin();
	string res;

	while (it != this->criancas.end()) {
		res += it->getNome();
		res += " : ";
		res += to_string(it->getIdade());
		res += "\n";

		it++;
	}

	return res;
}


Crianca& Jogo::perdeJogo(string frase)
{
	int npal = numPalavras(frase);
	list<Crianca>::iterator it = this->criancas.begin();
	int sz = criancas.size();
	cout << sz;

	while (sz > 1) {

		for (int i = 0; i < npal; i++) {
			if (it == criancas.end()) {
				it = criancas.begin();
			}
			else {
				it++;
			}

		}
		criancas.erase(it);
		sz--;
	}


	return *it;
}


list<Crianca>& Jogo::inverte()
{
	// a alterar
	return criancas;
}


list<Crianca> Jogo::divide(unsigned id)
{
	// a alterar
		list<Crianca> res;
		return res;
}


void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
	this->criancas = l1;
}


bool Jogo::operator==(Jogo& j2)
{
	// a alterar
	return true;
}


list<Crianca> Jogo::baralha() const
{
	// a alterar
	list<Crianca> res;
	return res;
}
