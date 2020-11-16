#include "Jogador.h"


void Jogador::adicionaAposta(const Aposta & ap)
{
	apostas.insert(ap);
}

unsigned Jogador::apostasNoNumero(unsigned num) const
{
	unsigned count = 0;

	tabHAposta::const_iterator it1 = apostas.begin();

	while (it1 != apostas.end()) {
		tabHInt numeros = it1->getNumeros();

		tabHInt::const_iterator it2 = numeros.begin();

		while (it2 != numeros.end()) {
			if (*it2 == num) {
				count++;
			}

			it2++;
		}

		it1++;
	}

	return count;
}


tabHAposta Jogador::apostasPremiadas(const tabHInt & sorteio) const
{
	tabHAposta money;
	tabHAposta::const_iterator it1 = apostas.begin();

	while (it1 != apostas.end()) {
		if (it1->calculaCertos(sorteio) >= 3) {
			money.insert(*it1);
		}

		it1++;
	}

	return money;
}












