#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "BST.h"


class PalavraSignificado {
      string palavra;
      string significado;
public:
       PalavraSignificado(string p, string s): palavra(p), significado(s) {}
       string getPalavra() const { return palavra; }
       string getSignificado() const { return significado; }
       void setSignificado(string sig) { significado = sig; }
       bool operator < (const PalavraSignificado &ps1) const;
       bool operator != (const PalavraSignificado &ps1) const;
};

class Dicionario
{
      BST<PalavraSignificado> palavras;
public:
      Dicionario(): palavras(PalavraSignificado("","")){};
      BST<PalavraSignificado> getPalavras() const;
      void lerDicionario(ifstream &fich);
      string consulta(string palavra) const;
      bool corrige(string palavra, string significado);
      void imprime() const;

};


// a alterar
class PalavraNaoExiste
{
	PalavraSignificado before;
	PalavraSignificado after;
public:
	PalavraNaoExiste(PalavraSignificado &b, PalavraSignificado &a) : before(b) , after(a) {};

	string getPalavraAntes() const { return before.getPalavra(); }
	string getSignificadoAntes() const { return before.getSignificado(); }
	string getPalavraApos() const { return after.getPalavra(); }
	string getSignificadoApos() const { return after.getSignificado(); }
};



#endif
