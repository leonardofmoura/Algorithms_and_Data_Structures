#ifndef JOGADOR_H_
#define JOGADOR_H_

#include "Aposta.h"
#include <string>

using namespace std;


struct apostaHash
{
	int operator() (const Aposta & ap) const
	{
		int sum = 0;
		int i = 1;
		tabHInt numeros = ap.getNumeros();
		tabHInt::const_iterator it = numeros.begin();

		while (it != numeros.end()) {
			sum += i*(*it);

			it++;
			i++;
		}

		return sum;
	}
	
	bool operator() (const Aposta & ap1, const Aposta & ap2) const
	{
		size_t certos = ap1.calculaCertos(ap2.getNumeros());

		if (certos == ap1.getNumeros().size()) {
			return true;
		}
		else {
			return false;
		}
	}
};

typedef unordered_set<Aposta, apostaHash, apostaHash> tabHAposta;


class Jogador
{
	tabHAposta apostas;
	string nome;
public:
	Jogador(string nm="anonimo") { nome=nm; }
	void adicionaAposta(const Aposta & ap);
	unsigned apostasNoNumero(unsigned num) const;
	tabHAposta apostasPremiadas(const tabHInt & sorteio) const;
	unsigned getNumApostas() const { return apostas.size(); }
};

#endif /*JOGADOR1_H_*/
