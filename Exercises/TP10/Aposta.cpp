#include "Aposta.h"
#include <iostream>
#include <sstream>

using namespace std;

bool Aposta::contem(unsigned num) const
{
	unordered_set<unsigned>::const_iterator it = numeros.begin();

	while (it != numeros.end()) {
		if (*it == num) {
			return true;
		}

		it++;
	}

	return false;
}


void Aposta::geraAposta(const vector<unsigned> & valores, unsigned n)
{

	unsigned int i = 0;
	while (numeros.size() != n) {

		numeros.insert(valores[i]);
		i++;
	}
}


unsigned Aposta::calculaCertos(const tabHInt & sorteio) const
{
	unsigned certos = 0;
	tabHInt::const_iterator it1 = numeros.begin();
	tabHInt::const_iterator it2 = sorteio.begin();

	while (it1 != numeros.end()) {

		while (it2 != sorteio.end()) {
			if (*it1 == *it2) {
				certos++;
			}

			//std::cout << *it1 << " " << *it2 << std::endl;

			it2++;
		}

		it1++;
		it2 = sorteio.begin();
	}

	return certos;
}




