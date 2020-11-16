#include <iostream>
#include <string>
#include <fstream>
#include "Dicionario.h"
#include "BST.h"

using namespace std;


BST<PalavraSignificado> Dicionario::getPalavras() const
{ return palavras; }



bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const
{
	return this->palavra < ps1.palavra;
}

bool PalavraSignificado::operator !=(const PalavraSignificado &ps1) const {
	return this->palavra != ps1.palavra;
}

string remove_newline(string st) {
	size_t elem = st.find("\r");

	if (elem != std::string::npos) {
		st.erase(st.begin() + elem);
	}

	return st;
}

void Dicionario::lerDicionario(ifstream &fich)
{
	string pal;
	string sig;

	while (!fich.eof()) {
		getline(fich, pal);
		getline(fich,sig);

		PalavraSignificado palsig(remove_newline(pal),remove_newline(sig));

		palavras.insert(palsig);
	}


}


string Dicionario::consulta(string palavra) const
{
	PalavraSignificado finding(palavra,"");
	PalavraSignificado pal = this->palavras.find(finding);
	PalavraSignificado not_found("","");
	bool reached_end = false;
	bool run = false;

	if (pal != not_found) {
		return pal.getSignificado();
	}
	else {

		BSTItrIn<PalavraSignificado> it(this->palavras);
		PalavraSignificado elem = it.retrieve();
		PalavraSignificado prev = it.retrieve();

		while(elem.getPalavra() < palavra) {
			run = true;
			prev = elem;
			it.advance();

			if (it.isAtEnd()) {
				reached_end = true;
				break;
			}

			elem = it.retrieve();
		}

		PalavraSignificado before = prev;
		PalavraSignificado after("","");

		if (!run) {
			before = after;
			after = elem;
		}
		if (!reached_end) {
			after = elem;
		}

	     throw PalavraNaoExiste(before,after);
	}
}


bool Dicionario::corrige(string palavra, string significado)
{
	PalavraSignificado not_found("","");
	PalavraSignificado finding(palavra,significado);
	PalavraSignificado pal = this->palavras.find(finding);

	if (pal != not_found) {
		palavras.remove(pal);
		palavras.insert(finding);
		return true;
	}
	else {
		palavras.insert(finding);
		return false;
	}
}


void Dicionario::imprime() const
{
	BSTItrIn<PalavraSignificado> it(this->palavras);

	while (!it.isAtEnd()) {
		PalavraSignificado elem = it.retrieve();
		cout << elem.getPalavra() << ": " << elem.getSignificado() << "\n";
		it.advance();
	}
}
